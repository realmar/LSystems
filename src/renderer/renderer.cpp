#include "render/renderer.hpp"
#include "builder/draw.hpp"

#include <iostream>
#include <cmath>
#include <limits>

#include <GL/freeglut.h>
#include <chrono>

using namespace realmar::builder;

namespace realmar::render {
    bool Vector2::operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool Vector2::operator!=(const Vector2& other) const {
        return !(*this == other);
    }

    Vector2 Vector2::operator-(const Vector2& other) const {
        return Vector2{x - other.x, y - other.y};
    }

    Vector3 Vector3::operator*(const double& scalar) const {
        return Vector3{x * scalar, y * scalar, z * scalar};
    }

    Vector3 Vector3::operator*=(const double& scalar) {
        Vector3 tmp = (*this) *  scalar;

        x = tmp.x;
        y = tmp.z;
        z = tmp.z;

        return *this;
    }

    void GlutTimerFunc(int) {
        glutPostRedisplay();
        glutTimerFunc(10, GlutTimerFunc, 0);
    }

    void OpenGLRenderer::Setup() {
        // this will be bad if trying to access those args
        // --> will produce a segfault
        int i = 1;
        std::vector<char*> c{'a'};

        glutInit(&i, &c[0]);

        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(width, height);
        glutInitWindowPosition(100, 100);

        window = glutCreateWindow("L-Systems");

        glutSetWindowData(reinterpret_cast<void*>(events.get()));

        rightClickMenu = glutCreateMenu(genericCallback(OnMenu));
        unsigned int counter = 0;

        auto names = facade.GetLSystemNames();
        std::for_each(names->begin(), names->end(), [&counter](const std::string& name) {
            glutAddMenuEntry(name.c_str(), counter++);
        });

        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glutDisplayFunc(genericCallback(Main));
        glutKeyboardUpFunc(genericCallback(OnKey));
        glutMouseWheelFunc(genericCallback(OnScroll));
        glutMouseFunc(genericCallback(OnMouse));

        glutPassiveMotionFunc(genericCallback(OnMotion));
        glutMotionFunc(genericCallback(OnMotion));

        glutTimerFunc(10, GlutTimerFunc, 0);

        events->Main = [this](auto self) {
            // MOUSE INPUT

            if(isMouseKeyDown) {
                Vector2 diff = currMousePos - lastMousePos;

                double scale = 0.01;

                // std::cout << diff.x << " : " << diff.y << std::endl;

                pos3.x += diff.x * scale;
                pos3.y -= diff.y * scale;
            }

            // GET INSTRUCTIONS

            DrawInstructions_ptr drawInstructions = facade.GetInstructionsForLSystem(lsystem, (unsigned int)iteration);

            // INIT FRAME

            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            // DRAW FRAME

            if(drawInstructions != nullptr) {
                for(auto i = drawInstructions->begin(); i < drawInstructions->end(); i++) {
                    (*i)->Execute(this);
                }
            }

            glLoadIdentity();

            glRasterPos2f(-1, -1);
            glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char *>("text to render"));

            // EVENTS

            glutSwapBuffers();
        };

        events->OnKey = [this](auto self, unsigned char key, int x, int y){
            switch (key) {
                case 'w':
                    this->iteration++;
                    break;
                case 's':
                    this->iteration = std::clamp(iteration - 1, 1, std::numeric_limits<int>::max());
                    break;
                case 'a':
                    currRotation += 10;
                    break;
                case 'd':
                    currRotation -= 10;
                    break;
                case 27:
                    glutLeaveMainLoop();
                default:
                    break;
            }
        };

        events->OnMouse = [this](auto self, int button, int state, int x, int y){
            switch (state) {
                case GLUT_DOWN:
                    isMouseKeyDown = true;
                    break;
                case GLUT_UP:
                    isMouseKeyDown = false;
                    break;
                default:
                    isMouseKeyDown = false;
                    break;
            }
        };

        events->OnScroll = [this](auto self, int wheel, int direction, int x, int y) {
            if(direction == 1) {
                scale3 *= 1.1;
            }else if(direction == -1) {
                scale3 *= 0.9;
            }
        };

        events->OnMenu = [this](auto self, int item) {
            iteration = 2;
            pos3 = Vector3{0, -1, 0};
            scale3 = Vector3{1, 1, 1};
            lsystem = facade.GetLSystemNames()->at(item);
        };

        events->OnMotion = [this](auto self, int x, int y) {
            lastMousePos = currMousePos;
            currMousePos = Vector2{(double)x, (double)y};

            // std::cout << "lastMouse: " << lastMousePos.x << " : " << lastMousePos.y << "currMouse: " << currMousePos.x << " : " << currMousePos.y << std::endl;
        };

        lsystem = facade.GetLSystemNames()->at(1);
    }

    void OpenGLRenderer::Teardown() {
        glutDestroyMenu(rightClickMenu);
        glutDestroyWindow(window);
    }

    void OpenGLRenderer::Render() {
        glutMainLoop();
    }

    // drawing
    void OpenGLRenderer::NewDrawing() {
        PullPen();
        glLoadIdentity();
        glTranslatef(pos3.x, pos3.y, pos3.z);
        glScalef(scale3.x, scale3.y, scale3.z);
        glRotatef(currRotation, 0, 0, 1);
    }

    void OpenGLRenderer::PutPen() {
        penDown = true;
    }

    void OpenGLRenderer::PullPen() {
        penDown = false;
    }

    void OpenGLRenderer::Move(const float &dist) {
        float y = dist * drawScale;

        if(penDown) {
            glBegin(GL_LINES);

            glVertex2f(0, 0);
            glVertex2f(0, y);

            glEnd();
        }

        glTranslatef(0, y, 0);
    }

    void OpenGLRenderer::Rotate(const float &degrees) {
        glRotatef(-degrees, 0, 0, 1);
    }

    void OpenGLRenderer::PushPosRot() {
        glPushMatrix();
    }

    void OpenGLRenderer::PopPosRot() {
        glPopMatrix();
    }
}


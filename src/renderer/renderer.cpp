#include "render/renderer.hpp"
#include "builder/draw.hpp"

#include <iostream>
#include <cmath>
#include <limits>

#include <GL/freeglut.h>
#include <chrono>

using namespace realmar::builder;

namespace realmar::render {
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
        glutInitWindowSize(512, 512);
        glutInitWindowPosition(100,100);

        glutCreateWindow("L-Systems");

        glutSetWindowData(reinterpret_cast<void*>(events.get()));

        glutCreateMenu(genericCallback(OnMenu));
        unsigned int counter = 0;

        auto names = facade.GetLSystemNames();
        std::for_each(names->begin(), names->end(), [&counter](const std::string& name) {
            glutAddMenuEntry(name.c_str(), counter++);
        });

        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glutDisplayFunc(genericCallback(Main));
        glutKeyboardUpFunc(genericCallback(OnKey));
        glutMouseWheelFunc(genericCallback(OnScroll));

        glutTimerFunc(10, GlutTimerFunc, 0);

        events->Main = [this](auto self) {
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
                default:
                    break;
            }
        };

        events->OnMenu = [this](auto self, int item) {
            iteration = 2;
            lsystem = facade.GetLSystemNames()->at(item);
        };

        lsystem = facade.GetLSystemNames()->at(1);
    }

    void OpenGLRenderer::Teardown() {
    }

    void OpenGLRenderer::Render() {
        glutMainLoop();
    }

    // drawing
    void OpenGLRenderer::NewDrawing() {
        PullPen();
        glLoadIdentity();
        glTranslatef(0, -1, 0);
    }

    void OpenGLRenderer::PutPen() {
        penDown = true;
    }

    void OpenGLRenderer::PullPen() {
        penDown = false;
    }

    void OpenGLRenderer::Move(const float &dist) {
        float y = dist * scale;

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


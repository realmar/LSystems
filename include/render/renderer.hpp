#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include <vector>
#include <memory>
#include <functional>

#include "render/interfaces.hpp"
#include "builder/ptrs.hpp"
#include "lsystem/facade.hpp"

#define genericCallback(functionName) \
    [](auto... args) { \
        auto pointer = reinterpret_cast<EventProxy*>(glutGetWindowData()); \
        if (pointer->functionName) pointer->functionName(pointer, args...); \
    }

namespace realmar::render {
    class Vector2 {
    public:
        double x = 0;
        double y = 0;

        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
    };

    class Vector3 {
    public:
        double x = 0;
        double y = 0;
        double z = 0;

        Vector3 operator*(const double& scalar) const;
        Vector3 operator*=(const double& scalar);
    };

    class EventProxy {
    public:
        std::function<void(EventProxy*)> Main = [](auto self) {  /* Default is do nothing */ };
        std::function<void(EventProxy*, int, int, int, int)> OnMouse = [](auto self, int, int, int, int) {  /* Default is do nothing */ };
        std::function<void(EventProxy*, int, int, int, int)> OnScroll = [](auto self, int, int, int, int) {  /* Default is do nothing */ };
        std::function<void(EventProxy*, unsigned char, int, int)> OnKey = [](auto self, unsigned char, int, int) {  /* Default is do nothing */ };
        std::function<void(EventProxy*, int)> OnMenu = [](auto self, int) {  /* Default is do nothing */ };
        std::function<void(EventProxy*, int, int)> OnMotion = [](auto self, int, int) {  /* Default is do nothing */ };
    };

    class OpenGLRenderer : public IRenderer {
    protected:
        std::shared_ptr<EventProxy> events = std::make_shared<EventProxy>();
        bool penDown = false;

        realmar::lsystem::LSystemFacade facade;
        int iteration = 1;
        std::string lsystem;

        Vector3 pos3{0, -1, 0};
        Vector3 scale3{1, 1, 1};

        Vector2 lastMousePos;
        Vector2 currMousePos;
        bool isMouseKeyDown = false;
    public:
        float drawScale = 0.008f;

        void Setup() override;
        void Teardown() override;
        void Render() override;

        // drawing
        void NewDrawing() override;
        void PutPen() override;
        void PullPen() override;
        void Move(const float &dist) override;
        void Rotate(const float &degrees) override;
        void PushPosRot() override;
        void PopPosRot() override;
    };
}

#endif //LSYSTEMS_RENDERER_HPP

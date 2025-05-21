#pragma once

#include<X3D.hpp>
#include<Vectors.hpp>
#include<Camera.hpp>
#include<Constants.hpp>
#include<Geometry.hpp>
#include<WindowManager.hpp>

//  foward declration
class WindowManager;

class Graphics {
public:
    WindowManager& wm;
    Camera cam;
    x3d math;

    Graphics(WindowManager& wm, Camera cam, x3d math): wm(wm), cam(cam), math(math){};
    ~Graphics() = default;

    void setColor(){
        SDL_SetRenderDrawColor(this->wm.renderer, 0.4, 0.1, 0.9, 1.0);
    }

    void line(Vec2 a, Vec2 b){
        SDL_RenderDrawLine(this->wm.renderer, a.x, a.y, b.x, b.y);
    }
};
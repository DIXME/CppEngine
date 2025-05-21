#pragma once

#include<X3D.hpp>
#include<Vectors.hpp>
#include<Camera.hpp>
#include<Constants.hpp>
#include<Geometry.hpp>
#include<WindowManager.hpp>



class Graphics {
public:
    WindowManager& wm;
    Camera cam;
    x3d math;

    Graphics(WindowManager& wm, Camera cam, x3d math): wm(wm), cam(cam), math(math){};
    ~Graphics() = default;

    Vec2 translate(Vec2 point){
        // top-down cords -> cordinate grid cords ( (0,0) is made the center  )
        return Vec2(point.x+wm.w/2,-point.y+wm.h/2);
    }

    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 1.0){
        SDL_SetRenderDrawColor(this->wm.renderer, r, g, b, a);
    }

    void line(Vec2 a, Vec2 b){
        a = this->translate(a);
        b = this->translate(b);
        SDL_RenderDrawLine(this->wm.renderer, a.x, a.y, b.x, b.y);
    }

    void connectPoints(points2d points){
        for(int i = 0; i < points.size()-1; i++){
            this->line(points[i], points[i+1]);
        };
        // connect the first point to the last point
        this->line(points[0],points[points.size()-1]);
    }

    void drawDebug(){
        // draw x & y axis
        this->line(Vec2(0,this->wm.h/2), Vec2(0,-this->wm.h/2));
        this->line(Vec2(-this->wm.w/2,0), Vec2(this->wm.w/2,0));
    }
};
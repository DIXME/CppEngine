#include<X3D.hpp>
#include<Vectors.hpp>
#include<Camera.hpp>
#include<Constants.hpp>
#include<Geometry.hpp>
#include<WindowManager.hpp>
#include<Graphics.hpp>
#include<Color.hpp>

Graphics::Graphics(WindowManager& wm, Camera cam, x3d math): wm(wm), cam(cam), math(math){};
Graphics::~Graphics() = default;

Vec2 Graphics::translate(Vec2 point){
    // top-down cords -> cordinate grid cords ( (0,0) is made the center  )
    return Vec2(point.x+wm.w/2,-point.y+wm.h/2);
}

void Graphics::setColor(short int r, short int g, short int b, short int a){
    SDL_SetRenderDrawColor(this->wm.renderer, r, g, b, a);
}

void Graphics::setColor(Color color){
    // FIX:
    // FUCKING STUPID
    SDL_SetRenderDrawColor(this->wm.renderer, color.get().r, color.get().g, color.get().b, color.get().a);
}

void Graphics::line(Vec2 a, Vec2 b){
    a = this->translate(a);
    b = this->translate(b);
    SDL_RenderDrawLine(this->wm.renderer, a.x, a.y, b.x, b.y);
}

void Graphics::connectPoints(points2d points){
    for(int i = 0; i < points.size()-1; i++){
        this->line(points[i], points[i+1]);
    };
    // connect the first point to the last point
    this->line(points[0],points[points.size()-1]);
}

void Graphics::drawDebug(){
    // draw x & y axis
    this->line(Vec2(0,this->wm.h/2), Vec2(0,-this->wm.h/2));
    this->line(Vec2(-this->wm.w/2,0), Vec2(this->wm.w/2,0));
}
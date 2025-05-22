#pragma once

#include<Camera.hpp>
#include<WindowManager.hpp>
#include<X3D.hpp>
#include<Vectors.hpp>
#include<Geometry.hpp>

class Graphics {
public:
    WindowManager& wm;
    Camera cam;
    x3d math;

    Graphics(WindowManager& wm, Camera cam, x3d math);
    ~Graphics();

    Vec2 translate(Vec2 point);

    void setColor(short int r, short int g, short int b, short int a = 1.0);

    void line(Vec2 a, Vec2 b);
    void connectPoints(points2d points);

    void drawDebug();
};
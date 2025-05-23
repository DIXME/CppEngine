#pragma once

#include<Graphics.hpp>

class Rect2Component : Component {
public:
    Vec2 pos, whv, vel;
    Color color;
    float rot, rotVel;

    Rect2Component(Vec2 pos, Vec2 whv, Color color);
    ~Rect2Component();

    rect2 rect();

    void draw(Component* parent);

    void tick(Component* parent);
};
#pragma once

#include<Color.hpp>
#include<Vectors.hpp>

// takes scene beacuse it should only be given scene by the scene or somthing like a group component
// forward declare here beacuse we only use a scene pointer
class Scene;

class Rect2Component : Component {
public:
    Vec2 pos, whv, vel;
    Color color;
    float rot, rotVel;

    Rect2Component(Vec2 pos, Vec2 whv, Color color);
    ~Rect2Component();

    rect2 rect();

    void draw(Scene* parent);
    void tick(Scene* parent);
};
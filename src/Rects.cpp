#include<Vectors.hpp>
#include<Component.hpp>
#include<Graphics.hpp>
#include<Color.hpp>
#include<Constants.hpp>
#include<Rects.hpp>
#include<X3D.hpp>
#include<Geometry.hpp>
#include<Scene.hpp>

Rect2Component::Rect2Component(Vec2 pos, Vec2 whv, Color color):
pos(pos),
whv(whv),
color(color),
vel(Vec2(0,0)),
rot(0.0),
Component(Root)
{}

Rect2Component::~Rect2Component(){}

rect2 Rect2Component::rect(){
    return rect2(this->pos, this->whv);
}

void Rect2Component::draw(Scene* Parent){
    (*Parent).g.setColor(this->color.get().r, this->color.get().g, this->color.get().b, this->color.get().a);
    (rot!=0)? (*Parent).g.connectPoints((*Parent).math_i.rotatePoints2(this->rect().verts(), this->rot)) : (*Parent).g.connectPoints(this->rect().verts());
}

void Rect2Component::tick(Scene* parent){
    Component::tickComponents();
    this->pos += this->vel;
    this->rot += this->rotVel;
    this->vel *= Vec2(Constants::friction);
    this->rotVel *= Constants::friction;
};
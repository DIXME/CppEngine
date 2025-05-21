#pragma once

#include<Vectors.hpp>
#include<Component.hpp>
#include<Graphics.hpp>
#include<Color.hpp>
#include<Constants.hpp>

class Rect2Component : Component {
public:
    Vec2 pos, whv, vel;
    Color color;
    float rot, rotVel;

    Rect2Component(Vec2 pos, Vec2 whv, Color color):
    pos(pos),
    whv(whv),
    color(color),
    vel(Vec2(0,0)),
    rot(0.0)
    {}
    ~Rect2Component(){}

    rect2 rect(){
        return rect2(this->pos, this->whv);
    }

    void draw(Graphics g, x3d math){
        g.setColor(this->color.gr(), this->color.gg(), this->color.gb(), this->color.ga());
        if(this->rot!=0) {g.connectPoints(math.rotatePoints2(this->rect().verts(), this->rot));} else{
            g.connectPoints(this->rect().verts());
        };
    }

    void tick(Graphics g, x3d math){
        this->tickComp(this);
        this->pos += this->vel;
        this->vel += this->rotVel;
        this->vel *= Vec2(Constants::friction);
        this->rotVel *= Constants::friction;
        this->draw(g,math);
    };
};
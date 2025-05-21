#pragma once

#include<iostream>

struct Color {
private:
    short int r, g, b, a;

public:
    Color(short int r = 225, short int g = 225, short int b = 225, short int a = 1.0): r(r), g(g), b(b), a(a){
        fix((*this));
    };

    void setColor(short int r = 225, short int g = 225, short int b = 225, short int a = 1.0){
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        if(this->check()){
            std::cout << "invalid color paramaters (color.setColor)";
        }
    };

    bool check(){
        return this->r > 225 || this->g > 225 || this->b > 225 || this->a > 1.0;
    }

    static void fix(Color c){
        if(c.check()){
            c.r=225;
            c.g=225;
            c.b=225;
            c.a=1.0;
        }
    }

    short int gr(){
        return this->r;
    }

    short int gg(){
        return this->g;
    }


    short int gb(){
        return this->b;
    }

    short int ga(){
        return this->a;
    }
};
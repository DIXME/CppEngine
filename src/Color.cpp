#include<iostream>
#include<Color.hpp>

Color::Color(short int r, short int g, short int b, short int a): color(color_t{r,g,b,a}){
    fix((*this));
};

Color::Color(color_t color): color(color){
    fix((*this));
};

bool Color::check(){
    return this->color.r > 225 || this->color.g > 225 || this->color.b > 225 || this->color.a > 1.0;
}

void Color::fix(Color c){
    if(c.check()){
        c.color.r=225;
        c.color.g=225;
        c.color.b=225;
        c.color.a=1.0;
    }
}

color_t& Color::get(){
    return this->color;
};

void Color::set(color_t color){
    this->color = color;
    this->fix((*this));
};

void Color::set(short int r, short int g, short int b, short int a){
    this->color = color_t{r,g,b,a};
    this->fix((*this));
};
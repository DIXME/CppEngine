#include<WindowManager.hpp>
#include<functional>
#include<iostream>
#include<Component.hpp>
#include<Keyboard.hpp>

void Keyboard::tick(){
    for(KeyBind& k : this->keys){
        // FIX: key presses with sdl2
        bool down = false;
        
        if(down && !k.down){ k.down = true; k.recent = true; };
        if(!down && k.down){ k.down = false; k.recent = true; };

        // we dont need to reset recent beacuse the statements below
        // already do this

        if(k.down && k.recent){
            // on down
            k.fnO();
            k.recent = false;
        };
        if(!k.down && k.recent){
            // on release
            k.fnR();
            k.recent = false;
        };
        if(k.down && !k.recent){
            // while down
            k.fnW();
        }
    }
}

void Keyboard::bind(KeyBind key){
    this->keys.push_back(key);
};

WindowManager Keyboard::getWm(){
    return this->wm;
}
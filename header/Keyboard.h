#pragma once

#include<WindowManager.h>
#include<functional>
#include<iostream>
#include<Component.h>

struct KeyBind {
public:
    int value;
    std::function<void()> fnW; // while down
    std::function<void()> fnO; // on key down
    std::function<void()> fnR; // when realsed
    bool down;
    bool recent;
};

class Keyboard : Component {
    // manges keyboard stuff
    // from the window manager
    // is game object!
    WindowManager wm;
    std::vector<KeyBind> keys;

    void tick(){
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
};
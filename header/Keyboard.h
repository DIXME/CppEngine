#pragma once

#include<GLFW/glfw3.h>
#include<WindowManager.h>
#include<functional>
#include<iostream>
#include<Types.h>
#include<vector>

class key {
public:
    std::string name;
    xTypes::voidFn fnW; // while down
    xTypes::voidFn fnO; // on key down
    xTypes::voidFn fnR; // when realsed
    bool down;
    bool recent;
};

class Keyboard {
    // manges keyboard stuff
    // from the window manager
    // is game object!
    WindowManager wm;
    xTypes::keyBinds keys;

    void tick(){
        for(key& k : this->keys){
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
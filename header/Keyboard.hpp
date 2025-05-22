#pragma once

#include<functional>
#include<iostream>
#include<WindowManager.hpp>

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
private:
    WindowManager wm;
    std::vector<KeyBind> keys;
public:
    void tick();
    void bind(KeyBind key);
    WindowManager getWm();
};
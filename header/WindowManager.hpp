#pragma once

#define SDL_MAIN_HANDLED
#include<iostream>
#include<SDL2/SDL.h>

// FIX: i was having problems with sdl2 & i used multiable chatgipity prompts to
// try to fix it to zero avail so i just tried to fix it myself and it was quite simple
// tbh so i need to clean this up a little bit

class WindowManager {
    // Creates & manages a sdl2 instance type shit   
public: 
    std::string title;
    int w, h;
    bool running;

    SDL_Window* window;
    SDL_Event event;
    SDL_Renderer* renderer;

    WindowManager(std::string title, int w, int h);
    ~WindowManager();

    int init();

    int rendererSetup();

    void pollEvents();

    bool isRunning();

    void clear();
    void loop();
    void kill();
};
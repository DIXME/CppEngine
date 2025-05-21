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

    WindowManager(std::string title, int w = 500, int h = 500):
        title(title), w(w), h(h), running(true), window(nullptr), renderer(nullptr) {
    }

    ~WindowManager() {
        std::cout << "WM CLASS DECONSTRUCTOR CALLED BY SOMTHING" << endl;
        this->kill();
    }

    int init() {
        std::cout << "init: SDL_Init\n";
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            return -1;
        }
        std::cout << "init: SDL_CreateWindow\n";
        window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            w, h,
            SDL_WINDOW_SHOWN
        );

        if (!window) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return -1;
        }
        std::cout << "init: rendererSetup\n";
        if (rendererSetup() != 1) {
            return -1;
        }
        std::cout << "init: success\n";
        running = true;
        return 0;
    }

    int rendererSetup(){
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
            this->kill();
            return -1;
        };
        return 1;
    }

    void pollEvents() {
        while(SDL_PollEvent(&this->event)) {
            switch(this->event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }

    bool isRunning() {
        pollEvents();
        return running;
    }

    void clear(){
        SDL_SetRenderDrawColor(renderer, 200, 150, 32, 255);
        SDL_RenderClear(renderer);
    }

    void loop() {
        SDL_RenderPresent(renderer);
    }

    void kill() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }
        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
            SDL_Quit();
            std::cout << "window KILLED\n";
        }
    }
};
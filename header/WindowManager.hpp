#pragma once
#define SDL_MAIN_HANDLED
#include<iostream>
#include<string>
#include<SDL2/SDL.h>

class WindowManager {
    // Creates & manages a sdl2 instance type shit   
public: 
    std::string title;
    int w, h;

    SDL_Window* window;
    SDL_Event event;

    WindowManager(std::string title, int w = 500, int h = 500):
    title(title),w(w), h(h){
        this->event = SDL_Event();
    }

    ~WindowManager(){
        this->kill();
    }

    int init(){
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout<<"no video\n";
            return 1;
        }
    
        this->window = SDL_CreateWindow(
            this->title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            this->w,
            this->h,
            SDL_WINDOW_SHOWN
        );

        std::cout<<"window made mabey\n";

        if (window == nullptr) {
            // Handle window creation error
            std::cout<<"window never existed\n";
            SDL_Quit();
            return 1;
        }

        // tell sdl where to put the event data;
        std::cout<<"polling event (window is made)\n";
        SDL_PollEvent(&this->event);
        return 0;
    }

    bool running(){
        if(this->event.type == SDL_QUIT){
            std::cout<<"window died\n";
        }
        return this->event.type != SDL_QUIT;
    }

    void kill(){
        std::cout<<"window KILLED\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};
#pragma once

#include<vector>

class Component;

class RootComponent {
public:
    std::vector<Component*> Components;

    RootComponent();
    ~RootComponent();
    
    bool addComponent(Component* Comp);

    // you would call this tick method in a game loop to
    // render and make everything function
    void tick();
    void tickComponents();
};
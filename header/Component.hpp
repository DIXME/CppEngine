#pragma once

#include<vector>
#include<variant>

// eveything in the scene will be a component

class Component {
public:
    RootComponent* Root;

    std::vector<Component*> Components;

    Component(RootComponent* Root);
    ~Component();
    
    void tick(std::variant<RootComponent*, Component*> Parent);
    void tickComponents();
};

class RootComponent {
public:
    std::vector<Component*> Components;

    RootComponent();
    ~RootComponent();
    
    // you would call this tick method in a game loop to
    // render and make everything function
    void tick();
    void tickComponents();
};
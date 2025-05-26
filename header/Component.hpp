#pragma once

#include<vector>
#include<variant>
#include<RootComponent.hpp>

// eveything in the scene will be a component
// Beacuse everything is a pointer you have to defref it
// FIX: is this an issue?

class Component {
public:
    RootComponent* Root;

    std::vector<Component*> Components;

    Component(RootComponent* Root);
    ~Component();
    
    void tick(std::variant<RootComponent*, Component*> Parent);
    void tickComponents();
};
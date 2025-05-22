#pragma once 

#include<vector>

class Component {
private:
    std::vector<Component> Components;

public:
    Component();
    ~Component();

    void componentsTick();

    void tickComp(Component* parent);
    
    // decendants should make ther component do whatevver it wants
    // in its own void tick function that the scene would call however
    // i can not put it here beacuse it might take diffrent args

    void addComponent(Component* comp);
};
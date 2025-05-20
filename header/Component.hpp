#pragma once 

#include<vector>

class Component {
private:
    std::vector<Component> Components;

public:
    Component(){}
    ~Component(){}

    void componentsTick(){
        for(Component& comp : this->Components){
            // tick all comps & give them yourself
            // so they can talk to eachother/interact
            comp.tick(this);
        };
    }

    void tick(Component* parent){
        this->componentsTick();
        // desdents overide this
    }

    void addComponent(Component* comp){
        // FIX: de refing pointers might not be a good
        // idea i dont really know
        this->Components.push_back((*comp));
    };
};
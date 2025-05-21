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
            // shouldnt call unless this comp has its own comps
            comp.tickComp(this);
        };
    }

    void tickComp(Component* parent){
        this->componentsTick();
        // desdents DONT overide this
    }
    
    // decendants should make ther component do whatevver it wants
    // in its own void tick function that the scene would call however
    // i can not put it here beacuse it might take diffrent args

    void addComponent(Component* comp){
        // FIX: de refing pointers might not be a good
        // idea i dont really know
        this->Components.push_back((*comp));
    };
};
#include<vector>
#include<Component.hpp>

Component::Component(){}
Component::~Component(){}

void Component::componentsTick(){
    for(Component& comp : this->Components){
        // tick all comps & give them yourself
        // so they can talk to eachother/interact
        // shouldnt call unless this comp has its own comps
        comp.tickComp(this);
    };
}

void Component::tickComp(Component* parent){
    this->componentsTick();
    // desdents DONT overide this
}

// decendants should make ther component do whatevver it wants
// in its own void tick function that the scene would call however
// i can not put it here beacuse it might take diffrent args

void Component::addComponent(Component* comp){
    // FIX: de refing pointers might not be a good
    // idea i dont really know
    this->Components.push_back((*comp));
};
#include<Component.hpp>
#include<RootComponent.hpp>
#include<typeinfo>

RootComponent::RootComponent(){};
RootComponent::~RootComponent() = default;

// component pointer should hold all derived classes

bool RootComponent::addComponent(Component* Comp){
    this->Components.push_back(Comp);
};

void RootComponent::tick(){};

void RootComponent::tickComponents(){
    // so basicly if we have any components we can call there ticks here 
    // so the point is every component can have infinte compoentes
    // example scene has 2 3d cubes
    for(Component* Comp : this->Components){
        (*Comp).tick(this);
    };
};
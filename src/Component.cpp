#include<Component.hpp>
#include<RootComponent.hpp>

// if we get a parent then we are a root compenet else we are not
Component::Component(RootComponent* Root): Root(Root){};
Component::~Component() = default;

void Component::tick(std::variant<RootComponent*, Component*> Parent){
    // is to be overidden by the child class
    // just examples
    if(std::holds_alternative<RootComponent*>(Parent)){
        // so this is the case where the component
        // is just the scene and this is not a sub-child
    } else if(std::holds_alternative<Component*>(Parent)) {
        // this is just if its a normal component
        // the else if is unseccary beacuse it is the only other option
        // but its just for readabilty or beacuse i think it looks nicer
    };
    // do somthing
};

void Component::tickComponents(){
    // so basicly if we have any components we can call there ticks here 
    // so the point is every component can have infinte compoentes
    // example 3d cube has 2 script components and the script
    for(Component* Comp : this->Components){
        (*Comp).tick(this);
    };
};
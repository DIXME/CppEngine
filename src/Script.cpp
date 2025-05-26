#include<Component.hpp>
#include<functional>
#include<Script.hpp>

ScriptComponent::ScriptComponent(): Component(Root){}
ScriptComponent::ScriptComponent(std::function<void(Component* parent)> script): script(script), Component(Root){}
ScriptComponent::~ScriptComponent(){}

void ScriptComponent::tick(Component* parent){
    Component::tickComponents();
    script(parent);
};
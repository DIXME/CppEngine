#include<Component.hpp>
#include<functional>
#include<Script.hpp>

ScriptComponent::ScriptComponent(){}
ScriptComponent::ScriptComponent(std::function<void(Component* parent)> script): script(script){}
ScriptComponent::~ScriptComponent(){}

void ScriptComponent::tick(Component* parent){
    this->componentsTick();
    script(parent);
}
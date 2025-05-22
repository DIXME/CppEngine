#pragma once

#include<Component.hpp>
#include<functional>

class ScriptComponent : Component {
    std::function<void(Component* parent)> script;

    ScriptComponent();
    ScriptComponent(std::function<void(Component* parent)> script);
    ~ScriptComponent();

    void tick(Component* parent);
};
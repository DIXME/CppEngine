#pragma once

#include<Camera.hpp>
#include<Component.hpp>
#include<Graphics.hpp>
#include<X3D.hpp>
#include<GameObjects.hpp>
#include<vector>

class Scene : public RootComponent {
public:
    // this is a or the root component
    x3d math_i; // math instance
    Camera cam; // main camera
    Graphics g; // graphics instance
    // game objects is just going to be our components

    Scene(x3d math_i, Camera cam, Graphics g);
    ~Scene();

    // no methods we just give the game objects ourselfs with there tick function
    // from our inhertied tickComps function
};
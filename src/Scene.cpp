#include<Scene.hpp>
#include<Camera.hpp>
#include<Component.hpp>
#include<Graphics.hpp>
#include<X3D.hpp>
#include<GameObjects.hpp>
#include<vector>

Scene::Scene(x3d math_i, Camera cam, Graphics g): math_i(math_i), cam(cam), g(g), RootComponent(){};
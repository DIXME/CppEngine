#pragma once

#include<Vectors.hpp>
#include<Component.hpp>

class Camera: Component {
public:
    Vec3 pos, rot, vel, rotVel;
    float near, far, aspect, fovRad, fovDeg;
    
    Camera(Vec3 pos, Vec3 rot, float near, float far, float aspect, int fov, bool isDeg = true);
    Camera(bool isDeg = true);
    
    static matrix projectionMatrix(Camera cam);
};
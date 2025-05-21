#pragma once

#include<Vectors.hpp>
#include<Matrix.hpp>
#include<x3dMath.hpp>
#include<x3dMath.hpp>
#include<Types.hpp>
#include<Component.hpp>
#include<math.h>

using namespace xTypes;

class Camera : Component {
public:
    Vec3 pos, rot, vel, rotVel;
    float near, far, aspect, fovRad, fovDeg;
    
    Camera(Vec3 pos, Vec3 rot, float near, float far, float aspect, int fov, bool isDeg = true):
    pos(pos),
    rot(rot),
    vel(Vec3(0)),
    rotVel(Vec3(0)),
    near(near),
    far(far),
    aspect(aspect),
    fovDeg(isDeg ? fov : Math::radToDeg(fov)),
    fovRad(isDeg ? Math::degToRad(fov) : fov)
    {};
    
    Camera(bool isDeg = true):
    pos(Vec3(0)),
    rot(Vec3(0)),
    vel(Vec3(0)),
    rotVel(Vec3(0)),
    near(0),
    far(0),
    aspect(4/3),
    fovDeg(isDeg ? 90 : Math::radToDeg(90)),
    fovRad(isDeg ? Math::degToRad(90) : 90)
    {};
    
    static matrix projectionMatrix(Camera cam){
        float f = (float)std::tan((float)cam.fovRad/2);
        return matrix(matrix_t{
            {1/f*cam.fovRad,0,0,0},
            {0,1/f,0,0},
            {0,0,cam.far+cam.near/cam.near-cam.far,2*cam.far*cam.near/cam.near-cam.far},
            {0,0,-1,0}
        });
    };
};
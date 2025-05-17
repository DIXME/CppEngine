#ifndef __CAMERA__
#define __CAMERA__

#include"Vectors.h"
#include"Matrix.h"
#include"math.h"

class Camera {
public:
    Vec3 pos, rot, vel, rotVel;
    float near, far, aspect, fov;
    
    Camera(Vec3 pos, Vec3 rot, float near, float far, float aspect, int fov) : pos(pos), rot(rot), vel(Vec3(0)), rotVel(Vec3(0)), near(near), far(far), aspect(aspect), fov(fov){};
    
    static matrix projectionMatrix(Camera cam){
        float f = (float)std::tan((float)cam.fov/2);
        return matrix(matrix_t{
            {1/f*cam.fov,0,0,0},
            {0,1/f,0,0},
            {0,0,cam.far+cam.near/cam.near-cam.far,2*cam.far*cam.near/cam.near-cam.far},
            {0,0,-1,0}
        });
    };
};

#endif
#ifndef __CAMERA__
#define __CAMERA__

#include"Vectors.h"
#include"Matrix.h"

class Camera {
public:
    Vec3 pos, rot, vel, rotVel;
    float near, far, aspect, fov;
    
    Camera(Vec3 pos, Vec3 rot, float near, float far, float aspect, int fov) : pos(pos), rot(rot), vel(Vec3(0)), rotVel(Vec3(0)), near(near), far(far), aspect(aspect), fov(fov){};
};

#endif
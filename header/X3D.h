#ifndef __X3D__
#define __X3D__

#include"Vectors.h"
#include"variant"
#include"Matrix.h"
#include<iostream>
#include<vector>
#include "Camera.h"

using namespace std;

class x3d {
public:
    using points2d = vector<Vec2>;
    using points3d = vector<Vec3>;
    Camera cam;
    x3d(Camera cam): cam(cam){};

    static points3d translatePoints(points3d points, Vec3 to){
        const Vec3 dist(to.invert());
        for( Vec3& v : points ){
            v += dist;
        }
        return points;
    };

    static points2d projectPoints(points3d points){
        points2d output({});
        for( Vec3& point : points ){
            // do somthing
        };
        return points2d();
    };
};

#endif
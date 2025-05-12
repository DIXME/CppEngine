#ifndef __X3D__
#define __X3D__

#include"Vectors.h"
#include"variant"
#include"Matrix.h"
#include<iostream>
#include<vector>
#include "Camera.h"

using namespace std;

namespace x3d {
    
    using points2d = vector<Vec2>;
    using points3d = vector<Vec3>;

    static points3d translatePoints(points3d points, Vec3 to){
        const Vec3 dist(to.invert());
        for( Vec3& v : points ){
            v += dist;
        }
        return points;
    };

    static Matrix<float> projectionMatrix(Camera cam){
        const float f = (float)1/tan(cam.fov/2);
        Matrix<float> mat = Matrix<float>({
            {f/cam.aspect,0,0,0},
            {0,f,0,0},
            {0,0,(cam.far+cam.near)/(cam.near-cam.far),2*cam.far*cam.near/(cam.near-cam.far)},
            {0,0,-1,0},
        });
    };

    static points2d projectPoints(points3d points, Camera cam){
        
        for( Vec3& point : points ){
            cout << point << endl;
        };
    }
}

#endif __X3D__
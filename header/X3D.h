#pragma once

#include<Vectors.h>
#include<variant>
#include<Matrix.h>
#include<iostream>
#include<vector>
#include<Camera.h>
#include<util.h>
#include<x3dMath.h>
#include<Types.h>

using namespace std;
using namespace xTypes;

class x3d {
public:
    // everything 3d math wise in one class
    // you should craete an instance if rendering!
    Camera cam;
    matrix projectionMatrix;
    x3d(Camera cam): cam(cam), projectionMatrix(cam.projectionMatrix(cam)){};

    static points3d translatePoints(points3d points, Vec3 to){
        const Vec3 dist(to.invert());
        for( Vec3& v : points ){
            v += dist;
        }
        return points;
    };

    points2d projectPoints(points3d points){
        points2d output({});
        for( Vec3 point : points ){
            // point3d -> matrix    3d space -> 2d space (screen)
            matrix mat(point, true);
            matrix matrix_result = this->projectionMatrix * mat;
            // matrix ->  point2d
            // when we do this we leave the z & w value to rot
            // mabey it is usefull for somthing
            output.insert( output.begin(), utl::Vec2FromMt(matrix_result) );
        };
        return output;
    };

    matrix rotationMatrix3dX(float rot) const {
        return matrix(matrix_t{
            { 1, 0, 0 },
            { 0, (float)cos((float)rot),-(float)sin((float)rot) },
            { 0, (float)sin((float)rot), (float)cos((float)rot) }
        });
    };

    matrix rotationMatrix3dY(float rot) const {
        return matrix(matrix_t{
            { (float)cos((float)rot), 0, (float)sin((float)rot) },
            { 0, 1, 0 },
            {-(float)sin((float)rot), 0, (float)cos((float)rot) }
        });
    }

    matrix rotationMatrix3dZ(float rot) const {
        return matrix(matrix_t{
            { (float)cos((float)rot),-(float)sin((float)rot), 0 },
            { (float)sin((float)rot), (float)cos((float)rot), 0 },
            { 0, 0, 1 }
        });
    }

    matrix rotate3dXYZ(Vec3 rot, Vec3 pos) const {
        // rotate one point
        matrix mat(pos);
        if(rot.z != 0){
            mat = rotationMatrix3dZ(rot.z) * mat;
        };
        if(rot.y != 0){
            mat = rotationMatrix3dY(rot.y) * mat;
        };
        if(rot.x != 0){
            mat = rotationMatrix3dX(rot.z) * mat;
        };
        return mat;
    };

    points3d rotatePoints(Vec3 rot, points3d points){
        // FIX: this dose not account for zeros so this can be optimizzed
        // this dose not use any other functions beacuse this is ment for multiable rotations
        // beacuse it only creates 3 matrices and dose not recreate them (it would if it where to use rotate3dXYZ)
        if(rot==Vec3(0)) return points;
        matrix z = rotationMatrix3dZ(rot.z);
        matrix y = rotationMatrix3dY(rot.y);
        matrix x = rotationMatrix3dX(rot.x);
        for( Vec3& point: points ){
            matrix mat(point);
            if(rot.z!=0) mat = z * mat;
            if(rot.y!=0) mat = y * mat;
            if(rot.x!=0) mat = x * mat;
            point = utl::Vec3FromMt(mat);
        }
        return points;
    }
};
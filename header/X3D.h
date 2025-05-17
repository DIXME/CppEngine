#ifndef __X3D__
#define __X3D__

#include"Vectors.h"
#include"variant"
#include"Matrix.h"
#include<iostream>
#include<vector>
#include "Camera.h"
#include"util.h"

using namespace std;

class x3d {
public:
    using points2d = vector<Vec2>;
    using points3d = vector<Vec3>;
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
        matrix z = rotationMatrix3dZ(rot.z);
        matrix y = rotationMatrix3dY(rot.y);
        matrix x = rotationMatrix3dX(rot.x);
        for( Vec3& point: points ){
            matrix mat(point);
            mat = z * mat;
            mat = y * mat;
            mat = x * mat;
            point = utl::Vec3FromMt(mat);
        }
        return points;
    }
};

#endif
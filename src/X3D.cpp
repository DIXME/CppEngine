#include<variant>
#include<iostream>
#include<vector>
#include<Camera.hpp>
#include<x3dMath.hpp>
#include<Vectors.hpp>
#include<Matrix.hpp>
#include<X3D.hpp>
#include<Geometry.hpp>
#include <cmath>


using namespace std;

x3d::x3d(Camera cam): cam(cam), projectionMatrix(cam.projectionMatrix(cam)){};

points3d x3d::translatePoints(points3d points, Vec3 to){
    const Vec3 dist(to.invert());
    for( Vec3& v : points ){
        v += dist;
    }
    return points;
};

points2d x3d::projectPoints(points3d points) const {
    points2d output({});
    for( Vec3 point : points ){
        // point3d -> matrix    3d space -> 2d space (screen)
        matrix mat(point, true);
        matrix matrix_result = this->projectionMatrix * mat;
        // matrix ->  point2d
        // when we do this we leave the z & w value to rot
        // mabey it is usefull for somthing
        output.insert( output.begin(), Vec2(matrix_result) );
    };
    return output;
};

matrix x3d::rotationMatrix3dX(float rot) const {
    return matrix(matrix_t{
        { 1, 0, 0 },
        { 0, (float)cos((float)rot),-(float)sin((float)rot) },
        { 0, (float)sin((float)rot), (float)cos((float)rot) }
    });
};

matrix x3d::rotationMatrix3dY(float rot) const {
    return matrix(matrix_t{
        { (float)cos((float)rot), 0, (float)sin((float)rot) },
        { 0, 1, 0 },
        {-(float)sin((float)rot), 0, (float)cos((float)rot) }
    });
}

matrix x3d::rotationMatrix3dZ(float rot) const {
    return matrix(matrix_t{
        { (float)cos((float)rot),-(float)sin((float)rot), 0 },
        { (float)sin((float)rot), (float)cos((float)rot), 0 },
        { 0, 0, 1 }
    });
}

matrix x3d::rotate3dXYZ(Vec3 rot, Vec3 pos) const {
    // rotate one point
    matrix mat(pos,false);
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

points3d x3d::rotatePoints(Vec3 rot, points3d points) const {
    // FIX: this dose not account for zeros so this can be optimizzed
    // this dose not use any other functions beacuse this is ment for multiable rotations
    // beacuse it only creates 3 matrices and dose not recreate them (it would if it where to use rotate3dXYZ)
    if(rot==Vec3(0)) return points;
    matrix z = rotationMatrix3dZ(rot.z);
    matrix y = rotationMatrix3dY(rot.y);
    matrix x = rotationMatrix3dX(rot.x);
    for( Vec3& point: points ){
        matrix mat(point,false);
        if(rot.z!=0) mat = mat * z;
        if(rot.y!=0) mat = mat * y;
        if(rot.x!=0) mat = mat * z;
        point = Vec3(mat);
    }
    return points;
};

Vec2 x3d::rotate2(Vec2 point, float rot) const {
    matrix mat = matrix_t{
        {std::cos(rot),-std::sin(rot)},
        {std::sin(rot), std::cos(rot)}
    };
    matrix pmt(point);
    Vec2 result(mat*pmt);
    return result;
};

points2d x3d::rotatePoints2(points2d points, float rot) const {
    for( Vec2& point : points ){
        point = this->rotate2(point, rot);
    }
    return points;
};
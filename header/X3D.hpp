#pragma once

#include<Camera.hpp>
#include<Matrix.hpp>
#include<Geometry.hpp>

class x3d {
public:
    // everything 3d math wise in one class
    // you should craete an instance if rendering!
    Camera cam;
    matrix projectionMatrix;
    x3d(Camera cam);

    static points3d translatePoints(points3d points, Vec3 to);

    points2d projectPoints(points3d points) const;

    matrix rotationMatrix3dX(float rot) const;

    matrix rotationMatrix3dY(float rot) const;

    matrix rotationMatrix3dZ(float rot) const;

    matrix rotate3dXYZ(Vec3 rot, Vec3 pos) const;

    points3d rotatePoints(Vec3 rot, points3d points) const;

    Vec2 rotate2(Vec2 point, float rot) const;
    
    points2d rotatePoints2(points2d points, float rot) const;
};
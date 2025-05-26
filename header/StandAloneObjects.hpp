#pragma once

#include<Vectors.hpp>
#include<X3D.hpp>
#include<Camera.hpp>
#include<Graphics.hpp>
#include<vector>

// define in a hpp beacuse nothing should use this any way
// and if it dose we can just add a src file

class Polygon {
public:
    points3d verts;
    Vec3 rot;
    Polygon(points3d verts): verts(verts){};
    ~Polygon() = default;
    void draw(Graphics g, Camera cam, x3d math){
        for(Vec3 vert : this->verts){
            g.connectPoints(math.projectPoints(math.rotatePoints(this->rot,this->verts)));
        };
    };
};
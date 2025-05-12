#ifndef __GEOMETRY__
#define __GEOMETRY__

#include"Vectors.h"
#include<iostream>
#include <vector>

using namespace std;

struct rect {
    Vec2 position, whv;

    rect(Vec2 position, Vec2 whv) : position(position), whv(whv){};

    vector<Vec2> verts(){
        return {
            Vec2(
                position.x - (whv.x/2),
                position.y - (whv.y/2)
            ),
            Vec2(
                position.x - (whv.x/2),
                position.y + (whv.y/2)
            ),
            Vec2(
                position.x + (whv.x/2),
                position.y + (whv.y/2)
            ),
            Vec2(
                position.x + (whv.x/2),
                position.y - (whv.y/2)
            )
        };
    }
};

struct rectprism {
    Vec3 position, whv;

    rectprism(Vec3 position, Vec3 whv) : position(position), whv(whv){};

    vector<Vec3> verts(){
        return {
            // back

            Vec3(
                position.x - (whv.x/2),
                position.y - (whv.y/2),
                position.z - (whv.z/2)
            ),
            Vec3(
                position.x - (whv.x/2),
                position.y + (whv.y/2),
                position.z - (whv.z/2)
            ),
            Vec3(
                position.x + (whv.x/2),
                position.y + (whv.y/2),
                position.z - (whv.z/2)
            ),
            Vec3(
                position.x + (whv.x/2),
                position.y - (whv.y/2),
                position.z - (whv.z/2)
            ),

            // front

            Vec3(
                position.x - (whv.x/2),
                position.y - (whv.y/2),
                position.z + (whv.z/2)
            ),
            Vec3(
                position.x - (whv.x/2),
                position.y + (whv.y/2),
                position.z + (whv.z/2)
            ),
            Vec3(
                position.x + (whv.x/2),
                position.y + (whv.y/2),
                position.z + (whv.z/2)
            ),
            Vec3(
                position.x + (whv.x/2),
                position.y - (whv.y/2),
                position.z + (whv.z/2)
            )
        };
    }

    vector<rect> faces(){
        const vector<Vec3> v = this->verts();
        const Vec3 
            // back
            bottomLeftBack,
            topLeftBack,
            topRightBack,
            bottomRightBack,
            // front
            bottomLeftFront,
            topLeftFront,
            topRightFront,
            bottomRightFront
            =
            v[0],v[1],v[2],v[3],
            v[4],v[5],v[6],v[7];
        // to do we need to project them first
        return {

        };
    }
};

#endif __GEOMETRY__
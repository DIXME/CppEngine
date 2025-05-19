#pragma once

#include"Vectors.h"
#include<iostream>
#include <vector>
#include"Types.h"

using namespace std;
using namespace xTypes;

struct rect2 {
    Vec2 position, whv;

    rect2(Vec2 position, Vec2 whv) : position(position), whv(whv){};

    points2d verts(){
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

struct rect3 {
    Vec3 position;
    Vec2 whv;

    rect3(Vec3 position, Vec2 whv) : position(position), whv(whv){};

    points3d verts(){
        return {
            Vec3(
                this->position.x - (whv.x/2),
                this->position.y - (whv.y/2),
                this->position.z
            ),
            Vec3(
                this->position.x - (whv.x/2), 
                this->position.y + (whv.y/2),
                this->position.z
            ),
            Vec3(
                this->position.x + (whv.x/2),
                this->position.y + (whv.y/2),
                this->position.z
            ),
            Vec3(
                this->position.x + (whv.x/2),
                this->position.y - (whv.y/2),
                this->position.z
            )
        };
    }
};

struct tri2 {
    Vec2 pos;
    Vec2 bh;

    tri2(Vec2 pos, Vec2 bh) : pos(pos), bh(bh){};

    points2d verts(){
        return points2d({
            Vec2(this->pos.x - this->bh.x/2, this->pos.y - this->bh.y/2),
            Vec2(this->pos.x + this->bh.x/2, this->pos.y - this->bh.y/2),
            Vec2(this->pos.x, this->pos.y + this->bh.y/2)
        });
    }
};

struct tri3 {
    Vec3 pos;
    Vec2 bh;

    tri3(Vec3 pos, Vec2 bh) : pos(pos), bh(bh){};

    points3d verts(){
        return points3d({
            Vec3(this->pos.x - this->bh.x/2, this->pos.y - this->bh.y/2,this->pos.z),
            Vec3(this->pos.x + this->bh.x/2, this->pos.y - this->bh.y/2,this->pos.z),
            Vec3(this->pos.x, this->pos.y + this->bh.y/2,this->pos.z)
        });
    }
};

struct rectprism {
    Vec3 position, whv;

    rectprism(Vec3 position, Vec3 whv) : position(position), whv(whv){};

    points3d verts(){
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

    vector<rect2> faces(){
        const points3d v = this->verts();
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
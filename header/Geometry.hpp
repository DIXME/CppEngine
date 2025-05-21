#pragma once

#include<Vectors.hpp>
#include<iostream>
#include<vector>
#include<Types.hpp>

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
        return points3d{
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
        const points3d verts_ = this->verts();
        
        // back face vertices
        const Vec3 bottomLeftBack = verts_[0];
        const Vec3 topLeftBack = verts_[1];
        const Vec3 topRightBack = verts_[2];
        const Vec3 bottomRightBack = verts_[3];
        
        // front face vertices
        const Vec3 bottomLeftFront = verts_[4];
        const Vec3 topLeftFront = verts_[5];
        const Vec3 topRightFront = verts_[6];
        const Vec3 bottomRightFront = verts_[7];

        return vector<rect2>{

        };
    }
};
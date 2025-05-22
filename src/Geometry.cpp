#include<vector>
#include<Vectors.hpp>
#include<Geometry.hpp>


using namespace std;

rect2::rect2(Vec2 position, Vec2 whv) : position(position), whv(whv){};

points2d rect2::verts(){
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

rect3::rect3(Vec3 position, Vec2 whv) : position(position), whv(whv){};

points3d rect3::verts(){
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

tri2::tri2(Vec2 pos, Vec2 bh) : pos(pos), bh(bh){};

points2d tri2::verts(){
    return points2d({
        Vec2(this->pos.x - this->bh.x/2, this->pos.y - this->bh.y/2),
        Vec2(this->pos.x + this->bh.x/2, this->pos.y - this->bh.y/2),
        Vec2(this->pos.x, this->pos.y + this->bh.y/2)
    });
}

tri3::tri3(Vec3 pos, Vec2 bh) : pos(pos), bh(bh){};

points3d tri3::verts(){
    return points3d({
        Vec3(this->pos.x - this->bh.x/2, this->pos.y - this->bh.y/2,this->pos.z),
        Vec3(this->pos.x + this->bh.x/2, this->pos.y - this->bh.y/2,this->pos.z),
        Vec3(this->pos.x, this->pos.y + this->bh.y/2,this->pos.z)
    });
}

rectprism::rectprism(Vec3 position, Vec3 whv) : position(position), whv(whv){};

points3d rectprism::verts(){
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

vector<rect2> rectprism::faces(){
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
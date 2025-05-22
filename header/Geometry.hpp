#pragma once

using namespace std;

using points2d = std::vector<Vec2>;
using points3d = std::vector<Vec3>;

struct rect2 {
    Vec2 position, whv;
    rect2(Vec2 position, Vec2 whv);
    points2d verts();
};

struct rect3 {
    Vec3 position;
    Vec2 whv;
    rect3(Vec3 position, Vec2 whv);
    points3d verts();
};

struct tri2 {
    Vec2 pos;
    Vec2 bh;
    tri2(Vec2 pos, Vec2 bh);
    points2d verts();
};

struct tri3 {
    Vec3 pos;
    Vec2 bh;
    tri3(Vec3 pos, Vec2 bh);
    points3d verts();
};

struct rectprism {
    Vec3 position, whv;
    rectprism(Vec3 position, Vec3 whv);
    points3d verts();
    vector<rect2> faces();
};
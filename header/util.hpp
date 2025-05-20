#pragma once

#include<Vectors.hpp>
#include<Matrix.hpp>

namespace utl {
    Vec3 Vec3FromMt(matrix mat){
        return Vec3(mat.at(0,0), mat.at(0,1), mat.at(0,2));
    };

    Vec2 Vec2FromMt(matrix mat){
        return Vec2(mat.at(0,0), mat.at(0,1));
    };
};
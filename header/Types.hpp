#pragma once

#include<vector>
#include<Vectors.hpp>
#include<functional>
#include<iostream>

// FIX: keyboard & types not working together no idea why
// why is this throwing an error with keyboard

namespace xTypes {
    using points2d = std::vector<Vec2>;
    using points3d = std::vector<Vec3>;

    using row = std::vector<float>;
    using col = std::vector<row>;
    using matrix_t = std::vector<std::vector<float>>;
};
#pragma once

#include"vector"
#include"Vectors.h"
#include<functional>
#include<iostream>
#include<Keyboard.h>

namespace xTypes {
    using points2d = std::vector<Vec2>;
    using points3d = std::vector<Vec3>;

    using row = std::vector<float>;
    using col = std::vector<row>;
    using matrix_t = std::vector<std::vector<float>>;

    // for things like callbacks
    using voidFn = std::function<void()>;
    using keyBinds = std::vector<key>;
};
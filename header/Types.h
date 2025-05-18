#ifndef  __TYPES__
#define __TYPES__

#include"vector"
#include"Vectors.h"

namespace types {
    using points2d = std::vector<Vec2>;
    using points3d = std::vector<Vec3>;

    using row = std::vector<float>;
    using col = std::vector<row>;
    using matrix_t = std::vector<std::vector<float>>;
}

#endif
#pragma once

#include<vector>
#include<functional>
#include<iostream>
#include<Vectors.hpp>

using row = std::vector<float>;
using col = std::vector<row>;

using matrix_t = std::vector<std::vector<float>>;

// Refrancces

using rowR = std::vector<float>&;
using colR = std::vector<row>&;
using colRR = std::vector<rowR>&;

class matrix {
private:
    matrix_t arr;

public:

    int currentX() const;

    int currentY() const;

    matrix(float number, int xl, int yl);

    matrix(matrix_t mat);

    // when we define these two other matrices contructors we have to do the tradianol way of assigning
    // properites beacuse otherwise we would be reassigning props if we do a : var(val) & a this->var=val;

    matrix(const Vec3& point, bool four_b);
    matrix(const Vec2& point);

    matrix mapX(std::function<float(float, int, int)> fn);

    matrix mapY(std::function<row(row, int)> fn);

    void forEachY(std::function<void(row, int)> fn);

    void forEachX(std::function<void(float, int, int)> fn);

    float at(int x, int y) const;

    friend std::ostream& operator<<(std::ostream& os, matrix& mat);

    // TODO: write all math oparations as overloads here!

    matrix operator*(const matrix& other) const;

    matrix operator^(float scalar) const;
};
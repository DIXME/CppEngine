#pragma once

#include<iostream>
class matrix;

class Vec3 {
public:
    float x, y, z;

    Vec3(float x, float y, float z);
    Vec3(float x);
    Vec3();

    Vec3(const matrix& mat);
    
    Vec3& operator+=(const Vec3& o);
    Vec3& operator-=(const Vec3& o);
    Vec3& operator/=(const Vec3& o);
    Vec3& operator*=(const Vec3& o);

    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator/(const Vec3& o) const;
    Vec3 operator*(const Vec3& o) const;

    bool operator==(Vec3 other) const;

    Vec3 invert();

    friend std::ostream& operator<<(std::ostream &os, const Vec3 &vec);
};

class Vec2 {
public:
    float x, y;

    Vec2(float x, float y);
    Vec2(float x);
    Vec2();

    Vec2(const matrix& mat);

    Vec2& operator+=(const Vec2& o);
    Vec2& operator-=(const Vec2& o);
    Vec2& operator/=(const Vec2& o);
    Vec2& operator*=(const Vec2& o);

    Vec2 operator+(const Vec2& o) const;
    Vec2 operator-(const Vec2& o) const;
    Vec2 operator/(const Vec2& o) const;
    Vec2 operator*(const Vec2& o) const;

    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);
};
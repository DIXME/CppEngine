#ifndef __VECTORS__
#define __VECTORS__
#include <iostream>
class Vec3 {
public:
    float x, y, z;

    Vec3(float x, float y, float z): x(x), y(y), z(z){};
    Vec3(float x): x(x), y(x), z(x){};
    Vec3(): x(0), y(0), z(0){};

    void operator+=(const Vec3& o) const {
        this->x+o.x;
        this->y+o.y;
        this->z+o.z;
    }
    
    void operator-=(const Vec3& o) const {
        this->x-o.x;
        this->y-o.y;
        this->z-o.z;
    }
    
    void operator/=(const Vec3& o) const {
        this->x/o.x;
        this->y/o.y;
        this->z/o.z;
    }

    void operator*=(const Vec3& o) const {
        this->x*o.x;
        this->y*o.y;
        this->z*o.z;
    }

    Vec3 operator+(const Vec3& o) const {
        return Vec3(
            this->x+o.x,
            this->y+o.y,
            this->z+o.z
        );
    }

    Vec3 operator-(const Vec3& o) const {
        return Vec3(
            this->x-o.x,
            this->y-o.y,
            this->z-o.z
        );
    }

    Vec3 operator/(const Vec3& o) const {
        return Vec3(
            this->x/o.x,
            this->y/o.y,
            this->z/o.z
        );
    }

    Vec3* operator*(const Vec3& o) const {
        return new Vec3(
            this->x*o.x,
            this->y*o.y,
            this->z*o.z
        );
    }

    Vec3 invert(){
        return Vec3(
            -this->x,
            -this->y,
            -this->z
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
        os << "(" << vec.x << "," << vec.y << ","  << vec.z << ")";  // Output the string
        return os;
    }
};

class Vec2 {
public:
    float x, y;

    Vec2(float x, float y): x(x), y(y){};
    Vec2(float x): x(x), y(x){};
    Vec2(): x(0), y(0){};

    void operator+=(const Vec2& o) const {
        this->x+o.x;
        this->y+o.y;
    }
    
    void operator-=(const Vec2& o) const {
        this->x-o.x;
        this->y-o.y;
    }
    
    void operator/=(const Vec2& o) const {
        this->x/o.x;
        this->y/o.y;
    }

    void operator*=(const Vec2& o) const {
        this->x*o.x;
        this->y*o.y;
    }

    Vec2 operator+(const Vec2& o) const {
        return Vec2(
            this->x+o.x,
            this->y+o.y
        );
    }

    Vec2 operator-(const Vec2& o) const {
        return Vec2(
            this->x-o.x,
            this->y-o.y
        );
    }

    Vec2 operator/(const Vec2& o) const {
        return Vec2(
            this->x/o.x,
            this->y/o.y
        );
    }

    Vec2 operator*(const Vec2& o) const {
        return Vec2(
            this->x*o.x,
            this->y*o.y
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
        os << "(" << vec.x << "," << vec.y << ")";  // Output the string
        return os;
    }
};

#endif __VECTORS__
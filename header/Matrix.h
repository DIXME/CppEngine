#ifndef __MATRICES__
#define __MATRICES__

#include<vector>
#include"Vectors.h"
#include<functional>

using namespace std;

using matrix_t = vector<vector<float>>;

class matrix {
private:
    matrix_t arr;

public:

    int currentX(){
        // returns current X length (cols)
        return this->arr[0].size();
    }

    int currentY(){
        // returns current Y length (rows)
        return this->arr.size();
    }

    matrix(float number = 0, int xl = 3, int yl = 3): arr(){
        this->arr = {};
        for(int y= 0; y< yl; y++){
            vector<float> xv = {};
            for(int x = 0; x < xl; x++){xv.push_back(number);}
            this->arr.push_back(xv);
        };
    };

    matrix(matrix_t mat): arr(mat){
        // we do nothing here
    };

    // when we define these two other matrices contructors we have to do the tradianol way of assigning
    // properites beacuse otherwise we would be reassigning props if we do a : var(val) & a this->var=val;

    matrix(Vec3 point, bool four_b = false){
        this->arr = matrix_t{ {point.x}, {point.y}, {point.z} };
        if(four_b){
            this->arr.push_back({0});
        };
    };

    matrix(Vec2 point, bool three_b = false){
        this->arr = matrix_t{ {point.x}, {point.y} };
        if(three_b){
            this->arr.push_back({0});
        };
    };

    matrix map(function<float(float)> fn){
        // this function will take a function and apply it to every number in our matrix array
        // the function we take will take the number (float) and do what ever it wants with it and return another float
        // the new float will be assinged to the orginal float and be stored in a matrix and returned to the user
        matrix mat(this->arr);
        for(int y = 0; y < this->currentY(); y++){
            for(int x = 0; x < this->currentX(); x++){
                mat.arr[y][x] = fn(mat.arr[y][x]);
            }
        };
        return mat;
    };

    float at(int x, int y){
        return this->arr[y][x];
    }

    friend std::ostream& operator<<(std::ostream& os, const matrix mat) {
        os << "{\n";
        
        os << "}";
        return os;
    }
};

#endif
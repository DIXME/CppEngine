#pragma once

#include<vector>
#include<Vectors.hpp>
#include<functional>
#include"Types.hpp"

using namespace std;
using namespace xTypes;

class matrix {
private:
    matrix_t arr;

public:

    int currentX(){
        // returns current X length (rows)
        return this->arr[0].size();
    };

    int currentY(){
        // returns current Y length (cols)
        return this->arr.size();
    };

    matrix(float number = 0, int xl = 3, int yl = 3): arr(){
        this->arr = {};
        for(int y= 0; y< yl; y++){
            row xv = {};
            for(int x = 0; x < xl; x++){xv.push_back((float)number);};
            this->arr.push_back(xv);
        };
    };

    matrix(matrix_t mat): arr(mat){};

    // when we define these two other matrices contructors we have to do the tradianol way of assigning
    // properites beacuse otherwise we would be reassigning props if we do a : var(val) & a this->var=val;

    matrix(const Vec3& point, bool four_b = false) : 
    arr(four_b ? matrix_t{{ {(float)point.x}, {(float)point.y}, {(float)point.z}, {0.0}}} :
                 matrix_t{ {(float)point.x}, {(float)point.y}, {(float)point.z} }){};

    matrix(const Vec2& point, bool three_b = false){
        this->arr = matrix_t{ {point.x}, {point.y} };
        if(three_b){
            this->arr.push_back({0});
        };
    };

    matrix mapX(function<float(float, int, int)> fn){
        // this function will take a function and apply it to every number in our matrix array
        // the function we take will take the number (float) and do what ever it wants with it and return another float
        // the new float will be assinged to the orginal float and be stored in a matrix and returned to the user
        matrix mat(this->arr);
        for(int y = 0; y < this->currentY(); y++){
            for(int x = 0; x < this->currentX(); x++){
                mat.arr[y][x] = fn(mat.arr[y][x], x, y);
            }
        };
        return mat;
    };

    matrix mapY(function<row(row&, int)> fn){
        // this function will take a function and apply it to every number in our matrix array
        // the function we take will take the number (float) and do what ever it wants with it and return another float
        // the new float will be assinged to the orginal float and be stored in a matrix and returned to the user
        matrix mat(this->arr);
        for(int y = 0; y < this->currentY(); y++){
            mat.arr[y] = fn(mat.arr[y], y);
        };
        return mat;
    };

    void forEachY(function<void(row, int)> fn){
        // this function will loop thru all of the numbers (floats) in the matrix array and give the function the number
        // this function will not return a value it will just do whatever it wants with it
        // the map function will allow you to do this but change the value!
        for(int y = 0; y < this->currentY(); y++){
            fn(this->arr[y], y);
        };
    };

    void forEachX(function<void(float, int, int)> fn){
        // this function will loop thru all of the numbers (floats) in the matrix array and give the function the number
        // this function will not return a value it will just do whatever it wants with it
        // the map function will allow you to do this but change the value!
        for(int y = 0; y < this->currentY(); y++){
            for(int x = 0; x < this->currentX(); x++){
                fn(this->arr[y][x], x, y);
            }
        };
    };

    float& at(int x, int y) {
        return this->arr[y][x];
    };

    friend std::ostream& operator<<(std::ostream& os, matrix& mat) {
        for(int y = 0; y < mat.currentY(); y++){
            os << "{ ";
            for(int x = 0; x < mat.currentX(); x++){
                os << mat.at(x,y);
                if(x+1<mat.currentX()){os << ", ";};
            }
            os << " }\n";
        };
        return os;
    };

    // TODO: write all math oparations as overloads here!

    matrix operator*(matrix& other) {
        // this function was implemented with ai (ai wrote it all)
        // i want to rewrite this function eveutly but i want to focus on other things
        // and i just dont want to do this right now
        // TODO: rewrite matrix oparation methods
        // FIX: AI
        int a_rows = this->currentY();  // m
        int a_cols = this->currentX();  // n
        int b_rows = other.currentY();  // n (must match a_cols)
        int b_cols = other.currentX();  // p

        if (a_cols != b_rows) {
            throw std::runtime_error(
                "Matrix dimensions do not match for multiplication: A.cols must equal B.rows."
            );
        }

        matrix_t result(a_rows, row(b_cols, 0.0f));

        for (int y = 0; y < a_rows; ++y) {
            for (int x = 0; x < b_cols; ++x) {
                float sum = 0.0f;
                for (int k = 0; k < a_cols; ++k) {
                    float a_val = this->arr[y][k];
                    float b_val = other.arr[k][x];
                    sum += a_val * b_val;
                }
                result[y][x] = sum;
            }
        }

        return matrix(result);
    }

    matrix operator^(float scalar) const {
        matrix result(this->arr);
        result=result.mapX(
            [&scalar](float value, int x, int y){
                return value*scalar;
            }
        );
        return result;
    }
};
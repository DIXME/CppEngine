#include "Vectors.h"
#include "X3D.h"
#include "Camera.h"
#include <iostream>

using namespace std;

void testVectors() {
    // this is just testing out my oparator overloads
    // and my vector classes in genaral
    Vec3 pos1 = Vec3(6,9,2);
    Vec3 pos2 = Vec3(7,3,4);
    Vec3 sum = pos1 + pos2;
    cout << pos1 << " + " << pos2 << " = " << sum << endl;

    Vec2 pos3 = Vec2(6,9);
    Vec2 pos4 = Vec2(7,3);
    Vec2 sum2 = pos3 * pos4;
    cout << pos3 << " + " << pos4 << " = " << sum2 << endl;
}

void testProjection() {
    Vec3 pos1 = Vec3(6,9,2);
    Vec3 pos2 = Vec3(7,3,4);
    Vec3 sum = pos1 + pos2;

    x3d::points3d points = {pos1, pos2, sum};
    Camera cam = Camera(Vec3(0), Vec3(0), 0, 0);
    x3d::projectPoints(points, cam);
}

int main(){
    testProjection();
    return 0;
}
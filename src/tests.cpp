#define SDL_MAIN_HANDLED

#include<SDL2/SDL.h>
#include<Engine.hpp>

using namespace std;

// so this file will just be unit test mabey i will make thhem into seprate files if this gets verry large
// i used to know steerling but idksteerling anymore❗❗‼️‼️🗣️🗣️🌹🌹🥀🥀🥀💔💔❓❓

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

void testMatrices() {
    Vec3 point(2);
    matrix mat(3);
    matrix matFromPoint(point,false);
    matrix mat4x1FromPoint(point, true);
    cout << mat << endl;
    matrix mat2 = mat.mapX(
        // so this is kinda like a marco thats applied to everything
        // TODO: i should be able to make the screens pixels a matrix and
        // use the map method to make a shader right?
        [](float num, int x, int y){
            return num + 1 + x + y;
        }
    );
    cout << mat2 << endl;
    matrix mat4 = mat.mapY(
        [](vector<float> r, int y){
            for(float& x : r){
                x+=2;
            }
            return r;
        }
    );
    cout << mat4 << endl;
}

void testMatrixOparations(){
    matrix mat1((float)3);
    Vec3 point(2,2,2);
    matrix mat2(point,false);
    matrix product = mat1 * mat2;
    cout << mat1  << " *  " << endl  << mat2 << endl << product << endl;  
};

void testProjection(){
    Vec3 point1(2);
    Vec3 point2(2,2,2);
    Vec3 point3(3);
    Camera cam(point1, point2, 0.1,1000,4/3,90,true);
    x3d d3(cam);
    points3d points({point1, point2, point3});
    points2d npoints = d3.projectPoints(points);
    for( Vec2& point : npoints ){
        cout << point << endl;
    }
}
/*
void atRefTest(){
    matrix mat(0);
    mat.at(1,1) = 5;
    cout << mat;
}
*/
void matrixDotTest(){
    matrix mat(2);
    mat=mat^2;
    cout << mat;
}

int testWm(){
    WindowManager wm("Hello World",1000,750);

    if(wm.init() != 0) {
        return -1;  // Exit if initialization fails
    }

    Camera cam(Vec3(0), Vec3(0),0.1,1000,4/3,90,true);
    x3d math(cam);
    Graphics g(wm,cam,math);
    Color coolColor1(100,50,100);
    Color coolColor2(50,25,30);
    Rect2Component rect(Vec2(0), Vec2(50), coolColor1);
    rect.rot = 5;

    while(wm.isRunning()) {
        wm.clear();
        g.setColor(0, 125, 0);
        g.drawDebug();

        rect.tick(g, math);
        
        wm.loop();
        SDL_Delay(16);    // Cap to ~60 FPS
    }

    return 0;
}

void sdlVersion(){
    SDL_version compiled;
    SDL_VERSION(&compiled);
    std::cout << "SDL compiled version: "
              << (int)compiled.major << "."
              << (int)compiled.minor << "."
              << (int)compiled.patch << std::endl;
}

int main(){
    return testWm();
}
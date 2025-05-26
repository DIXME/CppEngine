#include<Engine.hpp>
#include<iostream>

int main(){
    Camera cam;
    x3d math(cam);
    WindowManager wm("Hello World!", 800, 800);
    Graphics g(wm, cam, math);
    wm.init(); // show window and init everything sdl wise
    // the creation of vectors with one number will just set all other values to
    // the one provided example Vec2(0) == (0,0) Vec3(5) == (5,5,5)
    Color coolColor1(color_t{123,45,79,1});
    Color coolColor2(color_t{23,54,21,1});
    Color rainbow(color_t{0,0,0,0});
    Polygon poly(points3d{Vec3(-50,-25,0), Vec3(50,-25,0), Vec3(0,25,0)});
    while(wm.isRunning()){
        wm.clear();
        g.setColor(5,5,5,1);
        g.drawDebug();

        // draw other stuff
        g.setColor(rainbow);
        poly.draw(g,cam,math);
        
        poly.rot.x+=0.01;
        poly.rot.y+=0.01;
        poly.rot.z+=0.01;

        wm.loop();
        SDL_Delay(15);
    }
    return 0;
}
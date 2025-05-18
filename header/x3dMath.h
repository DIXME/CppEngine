#ifndef  __X3DMATH__
#define __X3DMATH__

#include"Constants.h"

namespace Math {
    static float radToDeg(float rad){
        // radians -> deegrees
        return rad * 180 / Constants::pi;
    }
    
    static float degToRad(float deg){
        // deegrees -> radians 
        return deg * Constants::pi / 180;
    }
}

#endif
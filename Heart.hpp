//
//  Heart.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//
#define GL_SILENCE_DEPRECATION
#ifndef Heart_hpp
#define Heart_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

class Heart {
public:
    float posx;
    float posy;
    
    Heart (float, float);
    void draw();
};



#endif /* Heart_hpp */

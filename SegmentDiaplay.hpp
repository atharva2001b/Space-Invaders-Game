//
//  SegmentDiaplay.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//

#define GL_SILENCE_DEPRECATION
#ifndef SegmentDiaplay_hpp
#define SegmentDiaplay_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>
//#include <String>

class SegmentDisplay{
    
public:
    float posx;
    float posy;
    std::string letter;
    
    void draw(int,float , float, float);
    SegmentDisplay(std::string);
    
};

#endif /* SegmentDiaplay_hpp */

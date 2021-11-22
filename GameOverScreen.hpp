//
//  GameOverScreen.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//

#ifndef GameOverScreen_hpp
#define GameOverScreen_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "SegmentDiaplay.hpp"
#include <vector>

class GameOverScreen{
public:
    void draw(std::vector<SegmentDisplay>&,std::vector<SegmentDisplay>&, std::vector<SegmentDisplay>&, bool, bool);
};

#endif /* GameOverScreen_hpp */

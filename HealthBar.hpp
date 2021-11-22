//
//  HealthBar.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//

#ifndef HealthBar_hpp
#define HealthBar_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Player.hpp"

class HealthBar{
public:
    float posx;
    float posy;
    int health = 100;
    
    void updateHealth(Player&);
    void draw();
    HealthBar(float, float);
};


#endif /* HealthBar_hpp */

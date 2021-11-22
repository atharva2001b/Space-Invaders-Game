//
//  Lazer.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//

#ifndef Lazer_hpp
#define Lazer_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Enemy.hpp"
#include <cmath>
#include <vector>

class Lazer{
public:
    float posx;
    float posy;
    bool active = true;
    
    Lazer(float, float);
    ~Lazer();
    void draw();
    void moveUp();
    int destroyEnemyIfNear(std::vector<Enemy*>&);
    
};
#endif /* Lazer_hpp */

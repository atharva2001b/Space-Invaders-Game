//
//  Player.hpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 19/11/21.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <GLFW/glfw3.h>

class Player{

private:
    int lives = 1;
    int health = 100;
    
public:
    float posx;
    bool isLiving = true;
    
    void draw();
    void translateLeft();
    void translateRight();
    void decreaseLives();
    void decreaseHealth();
    void increaseHealth(int powerUp);
    int getLives();
    void setLives(int);
    int getHealth();
    ~Player();
    
};
#endif /* Player_hpp */

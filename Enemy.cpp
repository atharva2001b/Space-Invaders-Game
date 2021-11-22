//
//  Enemy.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//

#define GL_SILENCE_DEPRECATION
#include "Enemy.hpp"


void Enemy::draw(){
    
    glBegin(GL_POLYGON);
    glVertex2f(-0.06 + posx, 0.02 + posy);
    glVertex2f(-0.1 + posx, 0.02 + posy);
    glVertex2f(-0.1 + posx, 0 + posy);
    glVertex2f(0.1 + posx, 0 + posy);
    glVertex2f(0.1 + posx, 0.02 + posy);
    glVertex2f(0.06 + posx, 0.02 + posy);
    glVertex2f(0.06 + posx, 0.06 + posy);
    glVertex2f(-0.06 + posx, 0.06 + posy);
    glVertex2f(-0.06 + posx, 0.02 + posy);
    glEnd();
    
    
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.08 + posx, 0 + posy);
    glVertex2f(-0.06 + posx, 0 + posy);
    glVertex2f(-0.07 + posx, -0.02 + posy);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.08 + posx, 0 + posy );
    glVertex2f(0.06 + posx, 0 + posy);
    glVertex2f(0.07 + posx, -0.02 + posy);
    glEnd();
}

void Enemy::move(){
    
    dir = -1*dir;
    
    if(dir == -1){
        posx += 0.08;
    }else{
        posx -= 0.08;
    }
}



Enemy::Enemy(float posx, float posy){
    this->posx = posx;
    this->posy = posy;
}


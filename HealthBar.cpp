//
//  HealthBar.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//

#define GL_SILENCE_DEPRECATION
#include "HealthBar.hpp"

void HealthBar::draw(){
    glBegin(GL_POLYGON);
    glVertex2f(0 + posx, 0 + posy);
    glVertex2f(((float)health/100)*(0.3) + posx, 0 + posy);
    glVertex2f(((float)health/100)*(0.3) + posx, 0.03 + posy);
    glVertex2f(0 + posx, 0.03 + posy);
    glEnd();
    
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0 + posx, 0 + posy);
    glVertex2f((0.3) + posx, 0 + posy);    glEnd();
    glEnd();
    
    //std::cout<<(((float)health/100))*(0.3)<<"- "<<this->health<<std::endl;
}


void HealthBar::updateHealth(Player& player){
    
    this->health = player.getHealth();
    
}

HealthBar::HealthBar(float posx, float posy){
    this->posx = posx;
    this->posy = posy;
}

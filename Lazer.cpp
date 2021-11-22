//
//  Lazer.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//
#define GL_SILENCE_DEPRECATION
#include "Lazer.hpp"

void Lazer::draw(){
    
    //draw triangle
    glBegin(GL_POLYGON);
    glVertex2f(0.005 + posx, 0.07 + posy);
    glVertex2f(0.005 + posx, 0 + posy);
    glVertex2f(-0.005 + posx, 0 + posy);
    glVertex2f(-0.005+ posx, 0.07 + posy);
    glEnd();
    
}

Lazer::Lazer(float posx, float posy){
    this->posx = posx;
    this->posy = -0.80;
}

void Lazer::moveUp(){
    posy += 0.05;
}

Lazer::~Lazer(){
    //
    std::cout<<"bullet distruct - "<<std::endl;;
}

int Lazer::destroyEnemyIfNear(std::vector<Enemy*>& enemies){
    
    for(int i = 0; i< enemies.size(); i++){
        
        float distanceBtw = sqrt(pow((posx - enemies[i]->posx),2) + pow((posy - enemies[i]->posy), 2));
        
            //std::cout<<"dist btw - "<<distanceBtw<<std::endl;
        
            if(distanceBtw < 0.12){
                enemies.erase(enemies.begin() + i);
                this->active = false;
                return -1;
            }
    }
    //std::cout<<std::endl<<std::endl;
    
    return 0;
    
}

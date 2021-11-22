//
//  Bullet.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//

#define GL_SILENCE_DEPRECATION
#include "Bullet.hpp"

void Bullet::draw(){
    
    //draw triangle
    glBegin(GL_POLYGON);
    glVertex2f(0.01 + posx, 0.05 + posy);
    glVertex2f(0.01 + posx, 0 + posy);
    glVertex2f(0 + posx, -0.02 + posy);
    glVertex2f(-0.01 + posx, 0 + posy);
    glVertex2f(-0.01 + posx, 0.05 + posy);
    glEnd();
}

Bullet::Bullet(float posx, float posy){
    this->posx = posx;
    this->posy = posy;
}

void Bullet::moveDown(){
    posy -= 0.05;
}

Bullet::~Bullet(){
    //
    //std::cout<<"bullet distruct - "<<std::endl;;
}

int Bullet::destroyPlayerIfNear(Player& player, std::vector<Heart*>& hearts, HealthBar& healthBar){
    
    float distanceBtw = sqrt(pow((posx - player.posx),2) + pow((posy + 0.85), 2));
    //std::cout<<"dist btw - "<<distanceBtw<<std::endl;
    
    if(distanceBtw < 0.15){
        if(player.getHealth() < 0){
                if(player.getLives() == 0){
                    return -2;
                    }else{
                        player.decreaseLives();
                        hearts.pop_back();
                        //std::cout<<"heart array size "<<std::endl;;
                    }
            player.increaseHealth(100);
            return -1;
            }else{
                if(player.getHealth() - 20 <= 0){
                    if(player.getLives() - 1 == 0){
                        return -2;
                    }
                    player.decreaseLives();
                    hearts.pop_back();
                    player.increaseHealth(100);
                    healthBar.updateHealth(player);
                    
                }else{
                    player.decreaseHealth();
                    healthBar.updateHealth(player);
                }
                
                //std::cout<<"player lif - "<<player.getLives()<<"-- health "<<player.getHealth()<<std::endl;;
                return -1;
            }
    }
    return 0;
}

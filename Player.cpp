//
//  Player.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 19/11/21.
//


#define GL_SILENCE_DEPRECATION
#include "Player.hpp"

void Player::draw(){
    
    //draw triangle
    glBegin(GL_POLYGON);
    glVertex2f(0.1 + posx, -0.82);
    glVertex2f(0.1 + posx, -0.85);
    glVertex2f(-0.1 + posx, -0.85);
    glVertex2f(-0.1 + posx, -0.82);
    glVertex2f(0 + posx, -0.77);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.080 + posx, -0.85);
    glVertex2f(-0.060 + posx, -0.85);
    glVertex2f(-0.070 + posx, -0.77);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.080 + posx, -0.85);
    glVertex2f(0.060 + posx, -0.85);
    glVertex2f(0.070 + posx, -0.77);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.03 + posx, -0.85);
    glVertex2f(-0.03 + posx, -0.85);
    glVertex2f(0 + posx, -0.70);
    glEnd();
}

void Player::translateLeft(){
    
    if(!(posx < (-0.8))){
        posx -= 0.05;
        return;
    }
    posx = -0.8;
    //std::cout<<posx<<std::endl;
}

void Player::translateRight(){
    
    if(!(posx > 0.8)){
        //std::cout<<"---"<<posx<<std::endl;
        posx += 0.05;
        return;
    }
    posx = 0.8;
    //std::cout<<posx<<std::endl;
}

void Player::decreaseLives(){
    lives--;
}

void Player::decreaseHealth(){
    health -= 40;
}

int Player::getLives(){
    return lives;
}

void Player::setLives(int newLife){
    lives = newLife;
}

int Player::getHealth(){
    return health;
}

void Player::increaseHealth(int powerUp){
    if(health <= 0 ){
        health = powerUp;
        return;
    }
    if(health + powerUp >= 100){
        health = 100;
        return;
    }
    health+=powerUp;
}

Player::~Player(){
    
}

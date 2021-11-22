//
//  Heart.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//

#include "Heart.hpp"


void Heart::draw(){
    
    glPointSize(1);
    //glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_POLYGON);
        for (float x = -1.139; x <= 1.139; x += 0.001)
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(0.03*x + posx, 0.03*y1 + posy);
            glVertex2f(0.03*x + posx, 0.03*y2 + posy);
        }
    glEnd();
    
}

Heart::Heart(float posx, float posy){
    this->posx = posx;
    this->posy = posy;
}


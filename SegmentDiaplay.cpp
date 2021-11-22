//
//  SegmentDiaplay.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 21/11/21.
//

#include "SegmentDiaplay.hpp"

void SegmentDisplay::draw(int width, float posx, float posy, float size){
    
//-------2vertical
    glLineWidth(width);
    
    if(letter[0] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0 + posx, 0 + posy);
            glVertex2f(0 + posx, 0.05*size + posy);
            glEnd();
    }
    
    if(letter[1] == '1'){
        glBegin(GL_LINES);
        glVertex2f(0 + posx, 0.05*size + posy);
        glVertex2f(0 + posx, 0.1*size + posy);
        glEnd();
    }
    
//---------2nd 2 vertical
    if(letter[2] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.05*size + posx, 0 + posy);
            glVertex2f(0.05*size + posx, 0.05*size + posy);
            glEnd();
    }
    
    if(letter[3] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.05*size + posx, 0.05*size + posy);
            glVertex2f(0.05*size + posx, 0.1*size + posy);
            glEnd();
    }
    
    
//----------middle 4 horizontal
    
    if(letter[4] == '1'){
        glBegin(GL_LINES);
        glVertex2f(0 + posx, 0.1*size + posy);
        glVertex2f(0.05*size + posx, 0.1*size + posy);
        glEnd();
    }
    
    if(letter[5] == '1'){
        glBegin(GL_LINES);
        glVertex2f(0 + posx, 0.05*size + posy);
        glVertex2f(0.025*size + posx, 0.05*size + posy);
        glEnd();
    }
    
    if(letter[6] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.025*size + posx, 0.05*size + posy);
            glVertex2f(0.05*size + posx, 0.05*size + posy);
            glEnd();
    }
    
    if(letter[7] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0 + posx, 0 + posy);
            glVertex2f(0.05*size + posx, 0 + posy);
            glEnd();
    }
    
    
//---------------slants /
    
    if(letter[8] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.05*size + posx, 0.1*size + posy);
            glVertex2f(0.025*size + posx, 0.05*size + posy);
            glEnd();
    }
    
    if(letter[9] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.025*size + posx, 0.05*size + posy);
            glVertex2f(0 + posx, 0 + posy);
            glEnd();
    }
    
    
//----------------slants \
    
    if(letter[10] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0 + posx, 0.1*size + posy);
            glVertex2f(0.025*size + posx, 0.05*size + posy);
            glEnd();
    }
    
    if(letter[11] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.025*size + posx, 0.05*size + posy);
            glVertex2f(0.05*size + posx, 0 + posy);
            glEnd();
    }
    
    if(letter[12] == '1'){
        glBegin(GL_LINES);
            glVertex2f(0.025*size + posx, 0 + posy);
            glVertex2f(0.025*size + posx, 0.1*size + posy);
            glEnd();
    }
    
    
    
}

SegmentDisplay::SegmentDisplay(std::string letter){
    this->letter = letter;
}

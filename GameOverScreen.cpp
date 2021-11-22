//
//  GameOverScreen.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 20/11/21.
//
#define GL_SILENCE_DEPRECATION
#include "GameOverScreen.hpp"

void GameOverScreen::draw(std::vector<SegmentDisplay>& ScoreText, std::vector<SegmentDisplay>& scoreText, std::vector<SegmentDisplay>& playAgainText, bool onPlayAgainHover, bool isMySonWinning){
    
    std::vector<SegmentDisplay> GameOverText;
    std::vector<SegmentDisplay> GameOverText2;
    std::vector<SegmentDisplay> YouText;
    std::vector<SegmentDisplay> WonText;
    
    
    GameOverText.push_back(SegmentDisplay("111010110000")); // G
    GameOverText.push_back(SegmentDisplay("001100101100")); // A
    GameOverText.push_back(SegmentDisplay("111100001010")); // M
    GameOverText.push_back(SegmentDisplay("110011010000")); // E
    //GameOverText.push_back(SegmentDisplay("000000000000")); // _
    GameOverText2.push_back(SegmentDisplay("111110010000")); // O
    GameOverText2.push_back(SegmentDisplay("110000001100")); // V
    GameOverText2.push_back(SegmentDisplay("110011010000")); // E
    GameOverText2.push_back(SegmentDisplay("110111100001")); // R
    
    YouText.push_back(SegmentDisplay("000000001110")); // Y
    YouText.push_back(SegmentDisplay("111110010000")); // O
    YouText.push_back(SegmentDisplay("111100010000")); // U
    //
    WonText.push_back(SegmentDisplay("111100000101")); // W
    WonText.push_back(SegmentDisplay("111110010000")); // O
    WonText.push_back(SegmentDisplay("111100000011"));  // N
    
    
    
    
    //std::cout<<" game won "<<isMySonWinning<<std::endl;
    
    
    if(!isMySonWinning){
        for(int i = 0; i < GameOverText.size(); i++){
                GameOverText[i].draw(15, -0.4 + i*0.25, 0.5, 3);
            }
            for(int i = 0; i < GameOverText2.size(); i++){
                GameOverText2[i].draw(15, -0.4 + i*0.25, 0.1, 3);
            }
    }else{
        for(int i = 0; i < YouText.size(); i++){
                YouText[i].draw(15, -0.3 + i*0.25, 0.5, 3);
            }
            for(int i = 0; i < WonText.size(); i++){
                WonText[i].draw(15, -0.3 + i*0.25, 0.1, 3);
            }
    }
    
    for(int i = 0; i < ScoreText.size(); i++){
        ScoreText[i].draw(10, -0.6 + i*0.15 , -0.3, 1.5);
    }
    
    for(int i = 0; i < scoreText.size(); i++){
        scoreText[i].draw(10, i*(-0.15) +0.7 , -0.3, 1.5);
    }
    
    for(int i = 0; i < playAgainText.size(); i++){
        if(onPlayAgainHover){
            playAgainText[i].draw(7, i*(0.1) + -0.4 , -0.7, 1);
        }else{
            playAgainText[i].draw(5, i*(0.09) + -0.35 , -0.675, 0.7);
        }
    }
    
    
    
    
}

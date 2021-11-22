//
//  main.cpp
//  AtariSpaceInvaders
//
//  Created by Atharva Bhosale on 19/11/21.
//
#include <GL/glew.h>
#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLFW/glfw3.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "GameOverScreen.hpp"
#include "Lazer.hpp"
#include "SegmentDiaplay.hpp"
#include <memory>
#include <vector>

//Make player obj
Player player = Player();

enum Game{ MENU_SCREEN = 0, GAME_PlAYING = 1, GAME_OVER = 2, GAME_INIT = 3};


std::vector<Enemy*> enemies = std::vector<Enemy*>();
std::vector<Bullet*> bullets = std::vector<Bullet*>();
std::vector<Lazer*> lazers = std::vector<Lazer*>();
std::vector<Heart*> hearts = std::vector<Heart*>();


HealthBar healthbar = HealthBar(0, 0.85);
int lazerManaCounter = 0;
int GameStatus = GAME_PlAYING;
int maxScore;
int currScore;
std::vector<int> score;
bool mouseOverReplayButton = false;
bool isMySonWinning = false;


std::vector<SegmentDisplay> LazerManaText;
std::vector<SegmentDisplay> Health;
std::vector<SegmentDisplay> LivesText;
std::vector<SegmentDisplay> ScoreText;
std::vector<SegmentDisplay> NumberText;
std::vector<SegmentDisplay> scoreText;
std::vector<SegmentDisplay> PlayAgainText;



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //std::cout<<key<<std::endl;
    
    if(key == GLFW_KEY_RIGHT){
        player.translateRight();
    }
    
    if(key == GLFW_KEY_LEFT){
        player.translateLeft();
    }
    
    if(key == GLFW_KEY_SPACE && action == GLFW_PRESS){
        if(lazerManaCounter ==100){
            lazers.push_back(new Lazer(player.posx, 0.85));
            lazerManaCounter = 0;
        }
        
    }
}

void initilizeGame(){
    
    GameStatus = GAME_PlAYING;
    
    enemies.clear();
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            enemies.push_back(new Enemy(-0.8 + i*0.3, 0.6 - 0.2 * j));
        }
    }
    
    
    hearts.clear();
    player.setLives(3);
    player.isLiving = true;
    player.increaseHealth(100);
    std::cout<<player.getHealth()<<std::endl;
    healthbar.updateHealth(player);
    isMySonWinning = false;
    
    for(int i = 0; i < player.getLives(); i++){
        hearts.push_back(new Heart ( 0.6 + i * 0.1  , 0.83 ));
    }
    
    maxScore = enemies.size();
}
    

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        initilizeGame();
    }
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    
    //std::cout<<"  x - "<<xpos<<", y - "<<ypos<<std::endl;
    
    if(xpos >= 169 && xpos <=523 && ypos >= 366 && ypos <= 424.5){
        mouseOverReplayButton = true;
    }else{
        mouseOverReplayButton = false;
    }
    
    
    if(mouseOverReplayButton){
        glfwSetMouseButtonCallback(window, mouse_button_callback);
    }
    
}



std::vector<int> numberToVec(int num){
    std::vector<int> ints;
    for(int i = 0; i < 4; i++ ){
        ints.push_back(num%10);
        num /= 10;
    }
    return ints;
}

void prepareTexts(){
    LazerManaText.push_back(SegmentDisplay("110000010000")); // L
    LazerManaText.push_back(SegmentDisplay("001100101100")); // A
    LazerManaText.push_back(SegmentDisplay("000010011100")); // Z
    LazerManaText.push_back(SegmentDisplay("110011010000")); // E
    LazerManaText.push_back(SegmentDisplay("110111100001")); // R
    
    Health.push_back(SegmentDisplay("111101100000")); // H
    Health.push_back(SegmentDisplay("110011010000")); // E
    Health.push_back(SegmentDisplay("001100101100"));  // A
    Health.push_back(SegmentDisplay("110000010000"));  // L
    Health.push_back(SegmentDisplay("0000100000001"));  //T
    Health.push_back(SegmentDisplay("111101100000")); // H
    
    LivesText.push_back(SegmentDisplay("110000010000")); // L
    LivesText.push_back(SegmentDisplay("0000100100001")); // I
    LivesText.push_back(SegmentDisplay("110000001100")); // V
    LivesText.push_back(SegmentDisplay("110011010000")); // E
    LivesText.push_back(SegmentDisplay("011011110000")); // S
    
    ScoreText.push_back(SegmentDisplay("011011110000")); // S
    ScoreText.push_back(SegmentDisplay("110010010000")); // C
    ScoreText.push_back(SegmentDisplay("111110010000")); // O
    ScoreText.push_back(SegmentDisplay("110111100001")); // R
    ScoreText.push_back(SegmentDisplay("110011010000")); // E
    
    PlayAgainText.push_back(SegmentDisplay("110111100000")); // P
    PlayAgainText.push_back(SegmentDisplay("110000010000")); //L
    PlayAgainText.push_back(SegmentDisplay("001100101100"));  // A
    PlayAgainText.push_back(SegmentDisplay("000000001110")); // Y
    PlayAgainText.push_back(SegmentDisplay("000000000000")); // _
    PlayAgainText.push_back(SegmentDisplay("001100101100"));  // A
    PlayAgainText.push_back(SegmentDisplay("111010110000")); // G
    PlayAgainText.push_back(SegmentDisplay("001100101100"));  // A
    PlayAgainText.push_back(SegmentDisplay("0000100100001")); // I
    PlayAgainText.push_back(SegmentDisplay("111100000011"));  // N
    
    
    NumberText.push_back(SegmentDisplay("111110011100")); // 0
    NumberText.push_back(SegmentDisplay("001100000000")); // 1
    NumberText.push_back(SegmentDisplay("100111110000")); // 2
    NumberText.push_back(SegmentDisplay("001111110000")); // 3
    NumberText.push_back(SegmentDisplay("011101100000")); // 4
    NumberText.push_back(SegmentDisplay("011011110000")); // 5
    NumberText.push_back(SegmentDisplay("111011110000")); // 6
    NumberText.push_back(SegmentDisplay("001110000000")); // 7
    NumberText.push_back(SegmentDisplay("111111110000")); // 8
    NumberText.push_back(SegmentDisplay("011111110000")); // 9

}




int main(int argc, const char * argv[]) {
    
    
    prepareTexts();
    
    
    //init glfw and window
    if (!glfwInit())
    {
        std::cout << "glfw init failed";
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders: Atari Classic Game", NULL, NULL);
    if (!window)
    {
        std::cout << "window init failed";
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetTime(0);
        
    
    //enemies.push_back(new Enemy(0,0.8));
    
    initilizeGame();
    
    
    int frameCounter = 0;
    int randTime = 3;
    
    
    GameOverScreen gameOverScreen = GameOverScreen();
    
    
    bool gameInit = false;
    scoreText.push_back(SegmentDisplay(NumberText[0]));
    scoreText.push_back(SegmentDisplay(NumberText[0]));
    scoreText.push_back(SegmentDisplay(NumberText[0]));
    
    //SegmentDisplay letter = SegmentDisplay("011011110000"); //L
    
    
    
    while (!glfwWindowShouldClose(window))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        
        
        //get mouse and keyboard events
        glfwPollEvents();
        
        //mouse events callback
        //glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetCursorPosCallback(window, cursor_position_callback);
        
        
        switch(GameStatus){
                
            case GAME_PlAYING:
            {
                // Keep running
                frameCounter++;
                
                gameInit = false;
                
                healthbar.draw();
                
                
                for(int i = 0; i < Health.size(); i++){
                    Health[i].draw(3, 0 + i*0.037, 0.9, 0.5);
                }
                for(int i = 0; i < LivesText.size(); i++){
                    LivesText[i].draw(3, 0 + i*0.037 + 0.58 , 0.9, 0.5);
                }
                for(int i = 0; i < LazerManaText.size(); i++){
                    LazerManaText[i].draw(3, 0 + i*0.037 + -0.6 , 0.9, 0.5);
                }
                
                for(int i = 0; i < ScoreText.size(); i++){
                    ScoreText[i].draw(3, 0 + i*0.037 + -0.95 , 0.90, 0.5);
                }
                
                for(int i = 0; i < scoreText.size(); i++){
                    scoreText[i].draw(3, 0 + i*(-0.037) + -0.82 , 0.83, 0.5);
                }
                
                
                
                //draw enemies
                for(Enemy *enemy: enemies){
                    enemy->draw();
                }
                
                for(Lazer *lazer: lazers){
                    if(lazer->active){
                        lazer->draw();
                    }
                    
                }
                
                if(lazerManaCounter != 100){
                    if(frameCounter%20 == 19){
                        if(lazerManaCounter + 10 > 100){
                            lazerManaCounter = 100;
                        }else{
                            lazerManaCounter += 10;
                        }
                    }
                }
                
                //drawLazerMana
                glBegin(GL_POLYGON);
                glVertex2f(-0.6 , 0.85);
                glVertex2f(((float)lazerManaCounter/100)*(0.3) - 0.6 , 0.85 );
                glVertex2f(((float)lazerManaCounter/100)*(0.3) - 0.6 , 0.88 );
                glVertex2f(-0.6 , 0.88 );
                glEnd();
                glBegin(GL_LINES);
                glVertex2f(-0.6 , 0.85);
                glVertex2f((0.3) - 0.6 , 0.85 );
                glEnd();
                
                
                
                
                int bulletIndex = 0;
                for(Bullet *bullet: bullets){
                    bullet->draw();
                    
                    if(bullet->destroyPlayerIfNear(player, hearts, healthbar) == -1){
                        bullets.erase(bullets.begin()+bulletIndex);
                    }else if (bullet->destroyPlayerIfNear(player, hearts, healthbar) == -2){
                        player.isLiving = false;
                        player.~Player();
                        GameStatus = GAME_OVER;
                    };
                    bulletIndex++;
                    
                }
                
                //draw player
                if(player.isLiving){
                    player.draw();
                }
                
                for(Heart* heart: hearts){
                    heart-> draw();
                }
                
                //std::cout<<hearts.size()<<std::endl;
                
                //bullet frequency
                int random = rand()%2;
                
                
                //for moving bullets (bullet speed)
                if(frameCounter%20 == 19){
                    for(Bullet *bullet: bullets){
                        bullet->moveDown();
                    }
                    
                }
                
                if(frameCounter%20 == 19){
                    
                    for(int k = 0; k < lazers.size(); k++){
                        if(lazers[k]->active){
                            lazers[k]->destroyEnemyIfNear(enemies);
                        }
                        if(lazers[k]->posy > 1){
                            lazers.erase(lazers.begin()+k);
                        }else{
                            lazers[k]->moveUp();
                        }
                    }
                    //std::cout<<lazers.size()<<std::endl;
                    
                    currScore = (maxScore - enemies.size())*50;
                    score = numberToVec(currScore);
                    scoreText.clear();
                    for(int i = 0; i < score.size(); i++){
                        //std::cout<<NumberText[score[i]].letter<<std::endl;
                        scoreText.push_back(SegmentDisplay(NumberText[score[i]]));
                    }
                    //std::cout<<std::endl;
                    
                }
                
                
                //for moving enemies and for firing bullets
                if(frameCounter == 200){
                    
                    for(Enemy *enemy: enemies){
                        enemy->move();
                    }
                    
                    frameCounter = 0;
                    randTime--;
                    if(randTime <= 0){
                        randTime = random;
                        //std::cout<<random<<std::endl;
                        int rand1 = (rand())%enemies.size();
                        if(enemies.size()!=0){
                            bullets.push_back(new Bullet(enemies[rand1]->posx,enemies[rand1]->posy));
                        }
                        
                    }
                }
                
                
                
                
                //delete fargone bullets as memory management
                for(int y  = 0; y < bullets.size(); y++){
                    if(bullets[y]->posy < -1.5){
                        bullets[y]->~Bullet();
                        bullets.erase(bullets.begin() + y);
                    }
                }
                
                if(enemies.size()==0){
                    isMySonWinning = true;
                    GameStatus = GAME_OVER;
                }
                
                break;
               
            }
            
            case GAME_OVER:{
                
                bullets.clear();
                enemies.clear();
                
                
                
                
                if(mouseOverReplayButton){
                    float x = 0.03;
                    float y = 0.04;
                    
                    glLineWidth(5);
                    glBegin(GL_LINES);
                    glVertex2f(-0.5 + x  , -0.57 + y);
                    glVertex2f(0.6 + x,-0.57 + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(0.6 + x,-0.57 + y);
                    glVertex2f(0.6 + x,-0.8 + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(0.6 + x,-0.8 + y);
                    glVertex2f(-0.5 + x,-0.8 + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(-0.5 + x, -0.57 + y);
                    glVertex2f(-0.5 + x,-0.8 + y);
                    glEnd();
                    
                }else{
                    
                    float x = 0.03;
                    float y = -0.03;
                    float boxSize = 0.9;
                    
                    glLineWidth(5);
                    glBegin(GL_LINES);
                    glVertex2f((-0.5)*boxSize + x  , (-0.57)*boxSize + y);
                    glVertex2f(0.6*boxSize + x,-0.57*boxSize + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(0.6*boxSize + x,-0.57*boxSize + y);
                    glVertex2f(0.6*boxSize + x,-0.8*boxSize + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(0.6*boxSize + x,-0.8*boxSize + y);
                    glVertex2f(-0.5*boxSize + x,-0.8*boxSize + y);
                    glEnd();
                    
                    glBegin(GL_LINES);
                    glVertex2f(-0.5*boxSize + x, -0.57*boxSize + y);
                    glVertex2f(-0.5*boxSize + x,-0.8*boxSize + y);
                    glEnd();
                    
                }
                
                
                gameOverScreen.draw(ScoreText, scoreText, PlayAgainText, mouseOverReplayButton, isMySonWinning);
                
                break;
            }
            
                
            case GAME_INIT:{
                
                //if(!gameInit){
                    //gameInit = true;
                //}
            }
        }
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    
    return 0;
}






#include "StateController.h"

void MenuMouse(int button, int state,int x, int y){        
    int fixedX = (float)mouseFixX(x);
    int fixedY = (float)mouseFixY(y);  
    
    if ((state == GLUT_UP)&&(button == GLUT_LEFT_BUTTON)){
        //Como todos os botoes tem o mesmo tamanho, e o X do centro e o mesmo podemos utilizar apenas um if
        if((fixedX >= (GAMEMENU_BUTTON_POSX - (GAMEMENU_BUTTON_WIDTH/2))) && (fixedX <= (GAMEMENU_BUTTON_POSX+(GAMEMENU_BUTTON_WIDTH/2)))){   

            if((fixedY >= GAMEMENU_BUTTON_START-(GAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= GAMEMENU_BUTTON_START+(GAMEMENU_BUTTON_HEIGHT/2))){
                selectState(LoadingState);    
                                          
            }else if((fixedY >= GAMEMENU_BUTTON_HIGHSCORES-(GAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= GAMEMENU_BUTTON_HIGHSCORES+(GAMEMENU_BUTTON_HEIGHT/2))){

            }else if((fixedY >= GAMEMENU_BUTTON_CREDITS-(GAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= GAMEMENU_BUTTON_CREDITS+(GAMEMENU_BUTTON_HEIGHT/2))){
                selectState(CreditsState);
            }else if((fixedY >= GAMEMENU_BUTTON_OPCOES-(GAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= GAMEMENU_BUTTON_OPCOES+(GAMEMENU_BUTTON_HEIGHT/2))){                
                selectState(OptionState);
            }else if((fixedY >= GAMEMENU_BUTTON_EXIT-(GAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= GAMEMENU_BUTTON_EXIT+(GAMEMENU_BUTTON_HEIGHT/2))){
                exit(0);
            }
        }
    }
    
}

void drawMenu(void) {    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    drawFullScreen(texturas[2]);//Desenha a textura do menu
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
}

void selectMenuState(){
    glutDisplayFunc(drawMenu);
    glutKeyboardFunc(NULL);
    glutKeyboardUpFunc(NULL);
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutMouseFunc(MenuMouse);
    playSound(0, 0);
}


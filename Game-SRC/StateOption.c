#include "StateController.h"

void optionMenuMouse(int button, int state,int x, int y){        
    int fixedX = (float)mouseFixX(x);
    int fixedY = (float)mouseFixY(y);  
    
    if ((state == GLUT_UP)&&(button == GLUT_LEFT_BUTTON)){
        
        if((fixedX >= (OPTION_BUTTON_VOLTAR_POSX - (OPTION_BUTTON_WIDTH/2))) && (fixedX <= (OPTION_BUTTON_VOLTAR_POSX+( OPTION_BUTTON_WIDTH/2)))){ 
            if((fixedY >= OPTION_BUTTON_VOLTAR_POSY-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_VOLTAR_POSY+(OPTION_BUTTON_HEIGHT/2))){                
                selectState(MenuState);               
            }
        }
        
        if((fixedX >= (OPTION_DIFICULDADE_POSX - (OPTION_BUTTON_WIDTH/2))) && (fixedX <= (OPTION_DIFICULDADE_POSX +(OPTION_BUTTON_WIDTH/2)))){   

            if((fixedY >= OPTION_BUTTON_POSY_1-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_1+(OPTION_BUTTON_HEIGHT/2))){
                
                selectState(MenuState);
            }else if((fixedY >= OPTION_BUTTON_POSY_2-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_2+(OPTION_BUTTON_HEIGHT/2))){
                
                selectState(MenuState);
            }else if((fixedY >= OPTION_BUTTON_POSY_3-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_3+(OPTION_BUTTON_HEIGHT/2))){
                
                selectState(MenuState);
            }else if((fixedY >= OPTION_BUTTON_POSY_4-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_4+(OPTION_BUTTON_HEIGHT/2))){              
                
                selectState(MenuState);
            }
        }
        
        if((fixedX >= (OPTION_RESOLUCAO_POSX - (OPTION_BUTTON_WIDTH/2))) && (fixedX <= (OPTION_RESOLUCAO_POSX +(OPTION_BUTTON_WIDTH/2)))){   

            if((fixedY >= OPTION_BUTTON_POSY_1-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_1+(OPTION_BUTTON_HEIGHT/2))){
                RESOLUTION_WIDTH = 640;
                RESOLUTION_HEIGHT = 360;
                glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
            }else if((fixedY >= OPTION_BUTTON_POSY_2-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_2+(OPTION_BUTTON_HEIGHT/2))){
                RESOLUTION_WIDTH = 1240;
                RESOLUTION_HEIGHT = 720;
                glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
            }else if((fixedY >= OPTION_BUTTON_POSY_3-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_3+(OPTION_BUTTON_HEIGHT/2))){
                RESOLUTION_WIDTH = 1600;
                RESOLUTION_HEIGHT = 900;
                glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
            }else if((fixedY >= OPTION_BUTTON_POSY_4-(OPTION_BUTTON_HEIGHT/2)) && (fixedY <= OPTION_BUTTON_POSY_4+(OPTION_BUTTON_HEIGHT/2))){                
                RESOLUTION_WIDTH = 1920;
                RESOLUTION_HEIGHT = 1080;
                glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
            }
        }
    }
    
}

void drawOptionsScreen(void) {    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    drawFullScreen(texturas[4]);//Desenha a textura do menu de opcoes
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
}


void selectOptionState(){
    glutDisplayFunc(drawOptionsScreen);
    glutKeyboardFunc(tecladoMenu);
    glutKeyboardUpFunc(NULL);
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutMouseFunc(optionMenuMouse);
}

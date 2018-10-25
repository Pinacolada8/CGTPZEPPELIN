#include "StateController.h"


void inGameMenuMouse(int button, int state,int x, int y){        
    int fixedX = (float)mouseFixX(x);
    int fixedY = (float)mouseFixY(y);  
    
    if ((state == GLUT_UP)&&(button == GLUT_LEFT_BUTTON)){
        //Como todos os botoes tem o mesmo tamanho, e o X do centro e o mesmo podemos utilizar apenas um if
        if((fixedX >= (INGAMEMENU_BUTTON_POSX - (INGAMEMENU_BUTTON_WIDTH/2))) && (fixedX <= (INGAMEMENU_BUTTON_POSX+(INGAMEMENU_BUTTON_WIDTH/2)))){

            if((fixedY >= INGAMEMENU_BUTTON_CONTINUAR-(INGAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= INGAMEMENU_BUTTON_CONTINUAR+(INGAMEMENU_BUTTON_HEIGHT/2))){
                closeInGameMenu();            
            }else if((fixedY >= INGAMEMENU_BUTTON_RESTART-(INGAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= INGAMEMENU_BUTTON_RESTART+(INGAMEMENU_BUTTON_HEIGHT/2))){
                selectState(GameState);    
                inGameMenuActive = False;
                restartGame();
            }else if((fixedY >= INGAMEMENU_BUTTON_MAINMENU-(INGAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= INGAMEMENU_BUTTON_MAINMENU+(INGAMEMENU_BUTTON_HEIGHT/2))){
                endGame();
                inGameMenuActive = False;
                selectState(MenuState);
            }else if((fixedY >= INGAMEMENU_BUTTON_EXIT-(INGAMEMENU_BUTTON_HEIGHT/2)) && (fixedY <= INGAMEMENU_BUTTON_EXIT+(INGAMEMENU_BUTTON_HEIGHT/2))){
                endGame();
                exit(0);
            }
        }
    }
    
}

void InGameMenuteclado(unsigned char key, int x, int y) {
    switch (key) {
        // Tecla ESC
        case 27:            
            closeInGameMenu();
            break;  
            
        default:
            break;            
    }
}

void selectInGameMenuState(){
    glutDisplayFunc(drawGame);
    glutKeyboardFunc(InGameMenuteclado);
    glutKeyboardUpFunc(NULL);
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutMouseFunc(inGameMenuMouse);
}
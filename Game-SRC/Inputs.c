
//Define que faz parte do pacote
#include <GL/glew.h>

#include "Geral.h"

//Controla todo o input do jogo

void teclado(unsigned char key, int x, int y) {
    switch (key) {
        // Tecla ESC
        case 27:
            activateInGameMenu();               
            break;
           
        case 'P':
        case 'p':
            fPause();
            break;
           
        case 'r':
        case 'R':
            restartGame();
            break;
            
        case 'w':
        case 'W':
            fowardVariation = 1;
            break;
            
        case 's':
        case 'S':
            fowardVariation = -1;
            break;

        case 'd':
        case 'D':
            rotationVariation = 1;          
            break;
            
        case 'a':
        case 'A':
            rotationVariation = -1;           
            break;
            
        case '1':
            cameraAtual = 0;
            cameraPitch = M_PI_4;
            break; 
            
        case '2':
            cameraAtual = 1;
            break; 
            
        case 'c':
        case 'C':
            if (cameraAtual < 5 && cameraAtual >= 1){
                cameraAtual++;
                if (cameraAtual >= 5 ){
                    cameraAtual = 1;
                }
            }  
            break;
            
        case '+':
            if (cameraAtual < 5 && cameraAtual >= 1 && cameraPitch < M_PI){
                cameraPitch += CAMERA_PITCH_SPEED;
            }   
            break;
            
        case '-':
            if (cameraAtual < 5 && cameraAtual >= 1 && cameraPitch > 0){
                cameraPitch -= CAMERA_PITCH_SPEED;
            }   
            break;
            
        case 'l':
        case 'L':
            lightON = !lightON;
            break;
            
        case 'f':
        case 'F':
            if (fogON){
                glDisable(GL_FOG);
                fogON = False;
            }else{
                glEnable(GL_FOG);
                fogON = True;
            }
            break;
            
        case 'N':
        case 'n':
            if (masterLight == GL_LIGHT0){
                masterLight = GL_LIGHT1;//Altera para a luz da lua
            }else{
                masterLight = GL_LIGHT0;//Altera para a luz do sol
            }
            break;            
            
        default:
            break;
    }
}

void tecladoRelease(unsigned char key, int x, int y) {
    switch (key) {        
        case 'w':
        case 'W':
            fowardVariation = 0;
            break;
            
        case 's':
        case 'S':
            fowardVariation = 0;
            break;

        case 'd':
        case 'D':
            rotationVariation = 0;         
            break;
            
        case 'a':
        case 'A':
            rotationVariation = 0;          
            break;  
        default:
            break;
    }
}

void specialKeysPress(int key,int x,int y){
    switch(key){
        case GLUT_KEY_UP:
            altitudeVariation = 1;
            break;
            
        case GLUT_KEY_DOWN:
            altitudeVariation = -1;
            break;           
     
        default:
            break;
    }               
}

void specialKeysRelease(int key,int x,int y){
    switch(key){   
        case GLUT_KEY_UP:
            altitudeVariation = 0;
            break;
        case GLUT_KEY_DOWN:
            altitudeVariation = 0;
            break;
            
        default:
            break;
    }   

}

float mouseFixX(int x){//Conserta a posicao do mouse em relacao ao glOrtho em qualquer resolucao
    return ((float)x * ((float)MAX_X/RESOLUTION_WIDTH));
}

float mouseFixY(int y){//Conserta a posicao do mouse em relacao ao glOrtho em qualquer resolucao
    return ((float)MAX_Y - ((float)y * ((float)(MAX_Y+FLOOR_DEPTH)/RESOLUTION_HEIGHT)));
}
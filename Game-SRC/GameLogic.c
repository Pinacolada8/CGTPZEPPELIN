#include <GL/glew.h>

#include "Geral.h"

#define UFO_ROTATIONSPEED 2 //Velocidade de rotacao do disco voador

const float tickFreq = 1000/TICK_MSEC;//Representa a Frequencia do programa
const float DefaultColor[] = {1,1,1,1};

bool lightON = True;
float rotationUFO = 0;


void endPause();
void startPause();

void fPause(){
    if (pause == False){
        startPause();
    }else{
        endPause();
    }
}

void startPause(){
    pause = True;
    pauseTimer();
}

void endPause(){
    if (pause != False) {
        pause = False;
        startTimer();
        tick(pause);
    }
}

void loadTimer(){//Inicia o timer do jogo
    initTimer();
}

void loadGame(){    
    srand(time(NULL));
    pause = True;
    loadTimer();
    startCameras();
    loadPlayer(PLAYER_STARTPOSX,PLAYER_STARTPOSY,PLAYER_STARTPOSZ,PLAYER_STARTANGLE,(float*)DefaultColor,CAMERA_QTDE,cameras, NULL);//ALTERAR
    startLights();
    endPause();
}

void endGame(){
    startPause();

    resetTimer();
}

void restartGame(){
    endGame();
    wait((tickFreq/2),loadGame);
}

void tick(int i){
    if (pause){//Para o jogo caso esteja pausado;
        return;
    }

    physicsUpdate();//Atualizacao da fisica do jogo (Movimento, ETC.)
    
    rotationUFO = (int)(rotationUFO + UFO_ROTATIONSPEED) % 360;

    glutTimerFunc(TICK_MSEC,tick,pause);
}

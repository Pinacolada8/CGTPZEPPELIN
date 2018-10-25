#include "Geral.h"

#define ZEPPELIN_SPEED_FOWARD 120 //Velocidade do dirigivel ir para frente
#define ZEPPELIN_SPEED_ROTATION 60 //Velocidade de rotacao da direcao do dirigivel
#define ZEPPELIN_SPEED_ALTITUDE 40 //Velocidade que o dirigivel pode ganhar ou perder altitude

int fowardVariation = 0;
int rotationVariation = 0;
int altitudeVariation = 0;


void physicsUpdate(){    
    player.y += altitudeVariation*(ZEPPELIN_SPEED_ALTITUDE)*(1/tickFreq);
    
    player.rotationAngle += rotationVariation*(ZEPPELIN_SPEED_ROTATION)*(1/tickFreq);
    
    player.z += fowardVariation*(ZEPPELIN_SPEED_FOWARD * cos(player.rotationAngle*(M_PI/180))*(1/tickFreq));
    player.x += fowardVariation*(ZEPPELIN_SPEED_FOWARD * sin(player.rotationAngle*(M_PI/180))*(1/tickFreq));
            
}



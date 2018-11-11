#include "Geral.h"

#define ZEPPELIN_SPEED_FOWARD 120 //Velocidade do dirigivel ir para frente
#define ZEPPELIN_SPEED_ROTATION 60 //Velocidade de rotacao da direcao do dirigivel
#define ZEPPELIN_SPEED_ALTITUDE 50 //Velocidade que o dirigivel pode ganhar ou perder altitude
#define ZEPPELIN_SPEED_BOOST 4 //Multiplicador do boost de velocidade

int fowardVariation = 0;
int rotationVariation = 0;
int altitudeVariation = 0;
int speedFoward = ZEPPELIN_SPEED_FOWARD;
bool fowardBoost = False;


void physicsUpdate(){    
    player.y += altitudeVariation*(ZEPPELIN_SPEED_ALTITUDE)*(1/tickFreq);
    
    if (fowardBoost){
        speedFoward = ZEPPELIN_SPEED_BOOST * ZEPPELIN_SPEED_FOWARD;
    } else{
        speedFoward = ZEPPELIN_SPEED_FOWARD;
    }
    
    player.rotationAngle += rotationVariation*(ZEPPELIN_SPEED_ROTATION)*(1/tickFreq);
    
    player.z += fowardVariation*(speedFoward * cos(player.rotationAngle*(M_PI/180))*(1/tickFreq));
    player.x += fowardVariation*(speedFoward * sin(player.rotationAngle*(M_PI/180))*(1/tickFreq));
            
}



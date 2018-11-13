#include "Geral.h"

const float CAMERAS_EYES[] = {0,8,0,
                              0,4,-4,
                              4,4,0,
                              0,4,4,
                              -4,4,0,
                              0,1,-6,
                                    }; // Posicao das cameras relativa ao jogador
const float CAMERAS_UPS[] = {0,0,1,
                             0,1,0,
                             0,1,0,
                             0,1,0,
                             0,1,0,
                             0,1,0,
                                    }; // Posicao dos vetores up
const float CAMERAS_CENTERS[] = {0,0,0,
                                 0,0,0,
                                 0,0,0,
                                 0,0,0,
                                 0,0,0,
                                 4,0,0,
                                    }; // Para onde as cameras estao olhando

CameraObject * cameras;
int cameraAtual = 0;
float cameraPitch = M_PI_4;
float cameraRotation = 0;
int cameraRotationDirection = 0;

void startCameras(){
    int i;
    cameras = malloc(CAMERA_QTDE*sizeof(CameraObject));
    
    for (i = 0;i<3*CAMERA_QTDE;i++){
        cameras[(int)i/3].center[i%3] = CAMERAS_CENTERS[i]; 
        
        cameras[(int)i/3].up[i%3] = CAMERAS_UPS[i]; 
        
        cameras[(int)i/3].eyeCorrection[i%3] = CAMERAS_EYES[i]; 
        
    }    
}

void cameraRotationUpdate(){
    if ((cameraAtual) == 5 && (cameraRotation > -M_PI_2) && (cameraRotation < M_PI_2)){
        cameraRotation += cameraRotationDirection* CAMERA_ROTATION_SPEED*(1/tickFreq);
    }    
}
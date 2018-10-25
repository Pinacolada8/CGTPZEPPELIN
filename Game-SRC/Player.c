#include "Geral.h"

PlayerObject player;//Representa uma instacia do objeto jogador


void loadPlayer(float x, float y, float z,float rotationAngle, float color[4], int CamerasQte,CameraObject * cameras, GLuint * TextId){
        
    player.x = x;
    player.y = y;
    player.z = z;
    player.rotationAngle = rotationAngle;
    
    player.camerasQte = CamerasQte;
    player.cameras = cameras;
    
    player.color[0]=color[0];
    player.color[1]=color[1];
    player.color[2]=color[2];
    player.color[3]=color[3];     
    
    player.TextId = TextId;

}
    


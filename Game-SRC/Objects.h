
#include <GL/glew.h>


typedef struct {//Objeto Pai, todos os outros objetos devem ter a estrutura minima igual a este
    GLuint * TextId;
    float x,y,z;
    float color[4];
}Object;

typedef struct {
    float eyeCorrection[3];//Arruma a posicao da camera em relacao ao objeto em que ela esta presa
    float center[3];
    float up[3];
}CameraObject;

typedef struct {
    GLuint * TextId;    
    float x,y,z;    
    float color[4];
    float rotationAngle;
    CameraObject * cameras;
    int camerasQte;    
}PlayerObject;

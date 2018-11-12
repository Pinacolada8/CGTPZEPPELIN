#include <GL/glew.h>

#include "Geral.h"

float masterLightPos[] = {1,1,0,0};
const float sunLightColor[] = {1,1,1,1};
const float sunLightAmbientColor[] = {0.35,0.35,0.35,1};
const float moonLightColor[] = {0.5,0.5,0.5,1};
const float moonLightAmbientColor[] = {0.05,0.05,0.05,1};
const float fogColor[] = {0.5,0.55,0.6,1};
const int  fogCoord[] = {0,0,0};


void configuraLights(){  
    //SUN~Start
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunLightAmbientColor);
    glLightfv(GL_LIGHT0,GL_POSITION,masterLightPos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sunLightAmbientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunLightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunLightColor);
    //glEnable(GL_LIGHT0);    
    //end~SUN
    
    //MOON~Start
    glLightfv(GL_LIGHT1,GL_POSITION,masterLightPos);
    glLightfv(GL_LIGHT1,GL_AMBIENT,moonLightAmbientColor);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, moonLightColor);
    glLightfv(GL_LIGHT1, GL_SPECULAR, moonLightColor);
    //glEnable(GL_LIGHT1);
    //MOON~End
}

void configuraFog(){
    glFogiv(GL_FOG_COORD_SRC, fogCoord);
    glFogi(GL_FOG_MODE, GL_EXP2); // Linear, exp. ou exp²
    glFogfv(GL_FOG_COLOR, fogColor); // Cor
    glFogf(GL_FOG_DENSITY, 0.001); // Densidade
    glHint(GL_FOG_HINT, GL_DONT_CARE); // Não aplicar se não puder
    glFogf(GL_FOG_START,VIEW_DISTANCE/1.2); // Profundidade inicial
    glFogf(GL_FOG_END,VIEW_DISTANCE-10); // Profundidade final      
}

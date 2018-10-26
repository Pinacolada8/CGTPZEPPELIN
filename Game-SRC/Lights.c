#include <GL/glew.h>

#include "Geral.h"

float sunLightPos[] = {1,1,0,0};
const float sunLightColor[] = {1,1,1,1};
const float sunLightAmbientColor[] = {0.35,0.35,0.35,1};
const float fogColor[] = {0.5,0.5,0.5,1};


void configuraLights(){  
    //SUN~Start
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunLightAmbientColor);
    glLightfv(GL_LIGHT0,GL_POSITION,sunLightPos);
    //glLightfv(GL_LIGHT0,GL_AMBIENT,sunLightAmbientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunLightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunLightColor);
    glEnable(GL_LIGHT0);
    //end~SUN
}

void configuraFog(){
    glFogi(GL_FOG_MODE, GL_EXP); // Linear, exp. ou exp²
    glFogfv(GL_FOG_COLOR, fogColor); // Cor
    glFogf(GL_FOG_DENSITY, 0.0005); // Densidade
    glHint(GL_FOG_HINT, GL_DONT_CARE); // Não aplicar se não puder
    glFogf(GL_FOG_START, 2000); // Profundidade inicial
    glFogf(GL_FOG_END,VIEW_DISTANCE); // Profundidade final      
}

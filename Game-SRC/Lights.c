#include <GL/glew.h>

#include "Geral.h"

float sunLightPos[] = {1,1,0,0};
const float sunLightColor[] = {1,1,1,1};
const float sunLightAmbientColor[] = {0.35,0.35,0.35,1};


void startLights(){  
    //SUN~Start
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunLightAmbientColor);
    glLightfv(GL_LIGHT0,GL_POSITION,sunLightPos);
    //glLightfv(GL_LIGHT0,GL_AMBIENT,sunLightAmbientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunLightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunLightColor);
    glEnable(GL_LIGHT0);
    //end~SUN
}

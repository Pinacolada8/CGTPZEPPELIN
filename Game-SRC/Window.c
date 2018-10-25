#include <GL/glew.h>

#include "Geral.h"

#define FOV_DEFAULT 60 // FOV Padrao

void configura3D(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(FOV_DEFAULT, ASPECT_RATIO, 1, VIEW_DISTANCE);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void atualizaTela() { //Faz com que o computador atue com a maior quantidade de fps que ele conseguirs
    glutPostRedisplay();
}

void redimensiona(int w, int h) {
    if ((w != RESOLUTION_WIDTH) || (h != RESOLUTION_HEIGHT)) {
        glutReshapeWindow(RESOLUTION_WIDTH, RESOLUTION_HEIGHT); //Resolucao somente podem ser alteradas pelo proprio jogo
    }

    glViewport(0, 0, w, h);

    configura3D();
}

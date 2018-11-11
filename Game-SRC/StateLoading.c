
#include <GL/glew.h>

#include "StateController.h"

GLubyte exec = 1;
GLubyte loaded = 0;

void loadingGame(){
    if (loaded == 0){        
        load_allModels();
        makeLists();
        loaded = 1;
    }       
    loadGame(); 
    selectState(GameState);
    exec = 1;
}

void drawLoadingScreen(void) {    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    drawFullScreen(texturas[5]);
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
    if (exec == 1){
        exec = 0;
        loadingGame();        
    }
    
}

void selectLoadingState(){
    glutDisplayFunc(drawLoadingScreen);
    glutKeyboardFunc(tecladoMenu);
    glutKeyboardUpFunc(NULL);
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutMouseFunc(NULL);    
}


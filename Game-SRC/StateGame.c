
#include <GL/glew.h>

#include "StateController.h"



void drawGame(void) {   
    int i;
    char aux[50];
    configura3D();    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);     
    
    //Camera~start     
    gluLookAt(player.cameras[cameraAtual].eyeCorrection[0]*sin(cameraPitch),player.cameras[cameraAtual].eyeCorrection[1]*cos(cameraPitch),player.cameras[cameraAtual].eyeCorrection[2]*sin(cameraPitch),
            player.cameras[cameraAtual].center[0],player.cameras[cameraAtual].center[1],player.cameras[cameraAtual].center[2],
            player.cameras[cameraAtual].up[0],player.cameras[cameraAtual].up[1],player.cameras[cameraAtual].up[2]);     
    //end~Camera
    
    //SkyBox~start
    glPushMatrix();
    glRotatef(player.rotationAngle,0,1,0);
    drawSkyBox(VIEW_DISTANCE,texturas[5]);
    glPopMatrix();
    //end~SkyBox
    
    if (lightON){ //Liga o esquema de iluminacao
        glEnable(GL_LIGHTING);
    }
    glEnable(masterLight);
    
    //ObjetoPrincipal~start
    drawUFO(&models[0],rotationUFO);
    //end~ObjetoPrincipal
    
    //Cenario~start    //ALTERAR
    glPushMatrix();
    //Movendo o cenario em relacao ao objeto principal    
    glRotatef(player.rotationAngle,0,1,0);
    glTranslatef(player.x,-player.y,-player.z);      
    glLightfv(masterLight,GL_POSITION,masterLightPos); //Luz Principal (SOL ou LUA)   
    glColor4f(1,1,1,1);
    glPushMatrix();    
    glScalef(CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER);
    glCallList(modelLists[2]);
    glPopMatrix();
    glPopMatrix();
    //end~Cenario
    
    glDisable(masterLight);
    glDisable(GL_LIGHTING);
    
    drawRelogio(TIMER_POSX,TIMER_POSY,getTimer());    
    
    //Coordenadas~start    
    sprintf(aux,"X:%.2f Y:%.2f Z:%.2f",player.x,player.y,player.z);
    drawTextHUD(1200,700,aux);
    //end~Coordenadas
    
    //Rotacao~start
    sprintf(aux,"RotationAngle: %.2f",player.rotationAngle);
    drawTextHUD(1200,650,aux);    
    //end~Rotacao
     
    if((pause == True) && (inGameMenuActive == False)){
        drawNotificationSquare(PAUSE_POSX,PAUSE_POSY,PAUSE_BASE,PAUSE_ALT, texturas[0]);
    }
    
    if(inGameMenuActive == True){
        drawNotificationSquare(INGAMEMENU_POSX,INGAMEMENU_POSY,INGAMEMENU_BASE,INGAMEMENU_ALT, texturas[1]);
    }
    
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
}

void selectGameState(){     
    glutDisplayFunc(drawGame);
    glutKeyboardFunc(teclado);
    glutKeyboardUpFunc(tecladoRelease);
    glutSpecialFunc(specialKeysPress);
    glutSpecialUpFunc(specialKeysRelease);    
    glutMouseFunc(NULL);
    glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);

}
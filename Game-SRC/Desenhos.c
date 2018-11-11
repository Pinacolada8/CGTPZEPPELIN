#include <GL/glew.h>

#include "Geral.h"

void drawTextHUD (int x,int y,char * str){
    //Para desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,MAX_X, -FLOOR_DEPTH, MAX_Y , -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glClear(GL_DEPTH_BUFFER_BIT);
    //----
    
    glColor4fv((float*)defaultColorTexto);
    texto(GLUT_BITMAP_HELVETICA_18, str, x, y);
    
    //Termina de desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    //----
}

void drawRelogio(int x,int y,unsigned long int relog){
    //Para desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,MAX_X, -FLOOR_DEPTH, MAX_Y , -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glClear(GL_DEPTH_BUFFER_BIT);
    //----
    
    glColor4fv((float*)defaultColorTexto);
    char number[12];
    int trash = snprintf(number,12,"Time: %lu",relog);
    texto(GLUT_BITMAP_HELVETICA_18, number, x, y);
    
    //Termina de desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    //----
}



void drawNotificationSquare(int x, int y,int base,int alt, GLuint idText){
    //Para desenhar em 2D
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,MAX_X, -FLOOR_DEPTH, MAX_Y , -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glClear(GL_DEPTH_BUFFER_BIT);
    //----
    
    base /=2;//Divide a base por 2 para facilitar operacoes
    alt /=2;//Divide a altura por 2 para facilitar operacoes
    
    glBindTexture(GL_TEXTURE_2D, idText);
    glColor4f(1,1,1,1);
    glPushMatrix();
    glTranslatef(x, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);glVertex2f(-base,-alt);//Valores referentes ao tamanho da imagem de pause
            glTexCoord2f(1, 0);glVertex2f(base,-alt);
            glTexCoord2f(1, 1);glVertex2f(base,alt);
            glTexCoord2f(0, 1);glVertex2f(-base,alt);
        glEnd();
    glPopMatrix();
    
    //Termina de desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    //----

}

void drawFullScreen(GLuint idText) {
    //Para desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,MAX_X, -FLOOR_DEPTH, MAX_Y , -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glClear(GL_DEPTH_BUFFER_BIT);
    //----
    
    glBindTexture(GL_TEXTURE_2D, idText); 
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0);glVertex2f(0,- FLOOR_DEPTH);
        glTexCoord2f(1,0);glVertex2f(MAX_X,-FLOOR_DEPTH);
        glTexCoord2f(1,1);glVertex2f(MAX_X,MAX_Y);
        glTexCoord2f(0,1);glVertex2f(0,MAX_Y);
    glEnd();
    
    //Termina de desenhar em 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    //----
}

void drawUFO(GLMmodel ** model, float rotation){
    glPushMatrix();
    glRotatef(rotation,0,1,0);
    glCallList(modelLists[0]);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glScalef(0.5,0.5,0.5);    
    //glRotatef(180,0,1,0);
    glRotatef(-90,1,0,0);    
    glCallList(modelLists[1]);
    //glmDraw(model[1],GLM_COLOR | GLM_SMOOTH );
    glPopMatrix();
}

void texturedSquare(GLuint idText){
    glBindTexture(GL_TEXTURE_2D, idText);
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0);glVertex3f(-1,-1,0);
        glTexCoord2f(1,0);glVertex3f(1,-1,0);
        glTexCoord2f(1,1);glVertex3f(1,1,0);
        glTexCoord2f(0,1);glVertex3f(-1,1,0);
    glEnd();
}

void drawSkyBox(int skyBoxDistance,GLuint *idText){
    glPushMatrix();      
        glScalef(skyBoxDistance,skyBoxDistance,skyBoxDistance);
        glTranslatef(0,-0.2,0);
        glPushMatrix(); //Front
            glTranslatef(0,0,1);    
            glRotatef(180,0,1,0);
            texturedSquare(idText[0]);
        glPopMatrix();
        glPushMatrix(); //Back
            glTranslatef(0,0,-1);            
            texturedSquare(idText[1]);
        glPopMatrix();
        glPushMatrix(); //Right
            glTranslatef(1,0,0);
            glRotatef(-90,0,1,0);
            texturedSquare(idText[2]);
        glPopMatrix();
        glPushMatrix(); //Left
            glTranslatef(-1,0,0);
            glRotatef(90,0,1,0);
            texturedSquare(idText[3]);
        glPopMatrix();        
        glPushMatrix(); //Up
            glTranslatef(0,1,0);
            glRotatef(-90,0,1,0);
            glRotatef(90,1,0,0);            
            texturedSquare(idText[4]);
        glPopMatrix();
        glPushMatrix(); //Down
            glTranslatef(0,-1,0);
            glRotatef(-90,0,1,0);
            glRotatef(-90,1,0,0);
            texturedSquare(idText[5]);
        glPopMatrix();
    glPopMatrix();
}

/*void drawSkyBox(int skyBoxDistance,GLuint idText){ //OLD CODE
    glPushMatrix();
    glScalef(skyBoxDistance,skyBoxDistance,skyBoxDistance);
    glBindTexture(GL_TEXTURE_2D, idText); 
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLE_FAN);//CIMA
        glTexCoord2f(0.2498,0.6658);glVertex3f(-0.5,0.5,-0.5);
        glTexCoord2f(0.4996,0.6658);glVertex3f(0.5,0.5,-0.5);
        glTexCoord2f(0.4996,1);glVertex3f(0.5,0.5,0.5);
        glTexCoord2f(0.2498,1);glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//Baixo
        glTexCoord2f(0.2498,0.6658);glVertex3f(-0.5,-0.5,-0.5);
        glTexCoord2f(0.4996,0.6658);glVertex3f(0.5,-0.5,-0.5);
        glTexCoord2f(0.4996,1);glVertex3f(0.5,-0.5,0.5);
        glTexCoord2f(0.2498,1);glVertex3f(-0.5,-0.5,0.5);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//FRONT
        glTexCoord2f(0.2498,0.3335);glVertex3f(-0.5,-0.5,-0.5);
        glTexCoord2f(0.4996,0.3335);glVertex3f(0.5,-0.5,-0.5);
        glTexCoord2f(0.4996,0.6658);glVertex3f(0.5,0.5,-0.5);
        glTexCoord2f(0.2498,0.6658);glVertex3f(-0.5,0.5,-0.5);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//BACK        
        glTexCoord2f(0.7494,0.3335);glVertex3f(0.5,-0.5,0.5);
        glTexCoord2f(1,0.3335);glVertex3f(-0.5,-0.5,0.5);
        glTexCoord2f(1,0.6658);glVertex3f(-0.5,0.5,0.5);
        glTexCoord2f(0.7494,0.6658);glVertex3f(0.5,0.5,0.5);        
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//LEFT
        glTexCoord2f(0,0.3335);glVertex3f(-0.5,-0.5,+0.5);
        glTexCoord2f(0.2498,0.3335);glVertex3f(-0.5,-0.5,-0.5);
        glTexCoord2f(0.2498,0.6658);glVertex3f(-0.5,+0.5,-0.5);
        glTexCoord2f(0,0.6658);glVertex3f(-0.5,+0.5,0.5);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//RIGHT
    glTexCoord2f(0.2498,0.3335);glVertex3f(+0.5,-0.5,-0.5);
        glTexCoord2f(0,0.3335);glVertex3f(+0.5,-0.5,+0.5);
        glTexCoord2f(0,0.6658);glVertex3f(+0.5,+0.5,0.5);
        glTexCoord2f(0.2498,0.6658);glVertex3f(+0.5,+0.5,-0.5);       
    glEnd();  
    glPopMatrix();
    
}*/

void drawCity(){
    int i,j;
    glPushMatrix();
    //Movendo o cenario em relacao ao objeto principal    
        glRotatef(player.rotationAngle,0,1,0);
        glTranslatef(player.x,-player.y,-player.z);      
        glLightfv(masterLight,GL_POSITION,masterLightPos); //Luz Principal (SOL ou LUA)   
        glColor4f(1,1,1,1);
        glPushMatrix();    
            glScalef(CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER);
            glTranslatef(-(CITY_BLOCK_QTDE/2)*CITY_BLOCK_SEPARATION,0,-(CITY_BLOCK_QTDE/2)*CITY_BLOCK_SEPARATION);
            for(i = 0;i<CITY_BLOCK_QTDE;i++){
                glPushMatrix();
                for (j=0;j<CITY_BLOCK_QTDE;j++){
                    glPushMatrix();
                        glRotatef(((i*j)%4)*90,0,1,0);//Gera uma rotacao para os blocos de cidade
                        glCallList(modelLists[2]);
                    glPopMatrix();
                    glTranslatef(CITY_BLOCK_SEPARATION,0,0);
                }
                glPopMatrix();
                glTranslatef(0,0,CITY_BLOCK_SEPARATION);
            } 
        glPopMatrix();
    glPopMatrix();    
}

/*void drawCity(){ //OLD CODE
    glPushMatrix();
    //Movendo o cenario em relacao ao objeto principal    
        glRotatef(player.rotationAngle,0,1,0);
        glTranslatef(player.x,-player.y,-player.z);      
        glLightfv(masterLight,GL_POSITION,masterLightPos); //Luz Principal (SOL ou LUA)   
        glColor4f(1,1,1,1);
        glPushMatrix();    
            glScalef(CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER,CITY_SCALEMULTIPLAYER);
            glCallList(modelLists[2]);
            glPushMatrix();
                glTranslatef(0,0,1.8);
                glScalef(1,1,-1);
                glCallList(modelLists[2]);
            glPopMatrix();            
        glPopMatrix();
    glPopMatrix();    
}*/


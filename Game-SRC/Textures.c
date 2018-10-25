#include <GL/glew.h>

#include "Geral.h"

#define QUANTIDADE_TEXTURAS 7 // Quantidade total de texturas utilizadas pelo programa

const char * paths [] = {//Local das texturas
    "GameResources/Textures/pause.png",             //0 -- Textura do Pause
    "GameResources/Textures/InGameMenu.png",        //1 -- Textura do In Game Menu
    "GameResources/Textures/Menu.png",              //2 -- Textura do Menu
    "GameResources/Textures/Credits.png",           //3 -- Textura dos Creditos
    "GameResources/Textures/Options.png",            //4 -- Textura das Opcoes
    "GameResources/Textures/SkyBox.png",            //5 -- Textura da Skybox
    "GameResources/Textures/Loading.png",            //6 -- Textura da tela de Loading
};


GLuint texturas[QUANTIDADE_TEXTURAS];    // id das texturas

GLuint load_texture(const char path[]) {
    GLuint id;   
    printf("%s\n",path);
    
  id = SOIL_load_OGL_texture(
    path,
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );

  if (id == 0) {
    printf("Erro carregando textura: '%s'\n", SOIL_last_result());
  }
  
  return id;
}

void load_allTextures (){
    int i;
    for (i=0;i<QUANTIDADE_TEXTURAS;i++){
        texturas[i] = load_texture(paths[i]);
    }
   
}
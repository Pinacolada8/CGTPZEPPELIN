#include "Geral.h"
#include "GLM/glm.h"

#define QUANTIDADE_OBJETOS3D 3 // Quantidade total de objetos 3D que sao carregados


const char * pathsModels [] = {//Local das texturas
    //"GameResources/Models/Cat/Cat.obj", //TEST Model       
    "GameResources/Models/UFO/UFO.obj",                 // 0 -- Modelo do OVNI
    "GameResources/Models/Alien/Alien.obj",               // 1 -- Modelo da Cidade(Base)
    "GameResources/Models/TheCity/TheCity.obj",         // 2 -- Modelo da Cidade(Base)
    //"GameResources/Models/Tropical_Islands/TropicalIslands.obj",// Cidade Com Problema
    //"GameResources/Models/Sirus5ColonialCity/sirus_city.obj",//Outra Cidade pesada
    //"GameResources/Models/CasteliaCity/CasteliaCity.obj",  //Cidade MUITO(MUITO MESMO) pesada, FPS extremamente baixo
    
};

GLMmodel ** models; //ID dos modelos 3D
GLuint modelLists[QUANTIDADE_OBJETOS3D];

GLMmodel * load_model(const char path[]) {
    GLMmodel * pmodel = NULL;
    
    printf("3D->%s\n",path);
    
    if (!pmodel) {
        pmodel = glmReadOBJ(path);
        if (!pmodel) {
            printf("\nFalha no carregamento do modelo.");
        }        
        glmUnitize(pmodel);
        glmVertexNormals(pmodel, 90.0, GL_TRUE);
    }
    return pmodel;
}

void load_allModels (){
    int i;
    models = malloc(QUANTIDADE_OBJETOS3D * sizeof(GLMmodel*));
    for (i=0;i<QUANTIDADE_OBJETOS3D;i++){      
        models[i] = load_model(pathsModels[i]);   
    }    
}

int modelToList(GLMmodel * model,GLuint mode){
    int listId;
    listId = glGenLists(1);
    glNewList(listId, GL_COMPILE);
        glmDraw(model,mode);
    glEndList();
    return listId;   
}

void makeLists(){
    int i;
    for (i=0;i<QUANTIDADE_OBJETOS3D;i++){      
        modelLists[i] = modelToList(models[i],GLM_TEXTURE | GLM_SMOOTH | GLM_COLOR);        
    }    
}
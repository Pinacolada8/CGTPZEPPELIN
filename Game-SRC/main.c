//Adiciona os outros arquivos, e variaveis universais e os includes
#include <GL/glew.h>
#include <GL/freeglut_std.h>


#include "Geral.h"



//Prototypes(main)
void atualizaTela();

//Variaveis Globais
int RESOLUTION_WIDTH = 1280;//RESOLUCAO
int RESOLUTION_HEIGHT = 720;//RESOLUCAO
bool pause = True;

int main(int argc, char** argv) {

    // Acordando o GLUT
    glutInit(&argc, argv);
    

    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    

    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 100);


    glutCreateWindow("Zeppelin");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //Configuracoes
       
    glEnable(GL_BLEND );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    //glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glClearColor(1, 1, 1, 1); 

    if (GLEW_OK != glewInit()) {
        // GLEW failed!
        printf("FALHA NO GLEW");
        exit(1);
    }   

    // Registrando Callbacks        
    glutIdleFunc(atualizaTela);   
    glutReshapeFunc(redimensiona);
    
    //Iniciando o jogo    
    configura3D();
    initSoundSystem();
    load_allTextures();
    load_allSounds();
    selectState(MenuState); 
    
    glutMainLoop();

    return (EXIT_SUCCESS);
}



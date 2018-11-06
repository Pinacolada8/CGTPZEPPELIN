
//Este Arquivo contem os Includes Globais do prjeto
//#include <SOIL/SOIL.h> //SOIL Antigo desatualizado, com problemas na source
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "FMOD/fmod.h"//Incluindo a biblioteca de FMOD para a utilizacao de sons
#include "SOIL/SOIL.h"//Incluindo a source do soil com edicoes para consertar problemas de deprecacao
#include "GLM/glm.h" //GLM library (Nate Robbins & Jeff Roggers) EDITADA PARA FUNCIONAR COM O SOIL E TGAs
#include "Objects.h"

//-------------------------

//Constantes universais
#define ASPECT_RATIO 1.777777778 //proporcao da tela
#define VIEW_DISTANCE 5000 // Distancia maxima da visao
#define FOV_DEFAULT 60 // FOV Padrao
#define MAX_X  1600 // Valor maximo de unidades na direcao X
#define MAX_Y  820 // Valor maximo de unidades na direcao Y(sem contar com a profundidade do chao)
#define FLOOR_DEPTH 80 //Profundidade do chao do jogo
#define TICK_MSEC 15.625 //Tempo em milisegundos em que devemos chamar a funcao para obter um tickrate de 64;

#define PAUSE_POSX 800 //Posicao X do pause
#define PAUSE_POSY 300 //Posicao Y do pause
#define PAUSE_BASE 300 // Tamanho da base da imagem do pause
#define PAUSE_ALT 300 // Tamanho da altura da imagem do pause

#define TIMER_POSX 150 //Posicao X do timer
#define TIMER_POSY 800 //Posicao Y do Relogio

#define INGAMEMENU_POSX 800 //Posicao X do in game menu
#define INGAMEMENU_POSY 300 //Posicao Y do in game menu
#define INGAMEMENU_BASE 300 // Tamanho da base da imagem do in game menu
#define INGAMEMENU_ALT 300 // Tamanho da altura da imagem do in game menu
#define INGAMEMENU_BUTTON_WIDTH 226 //Largura dos botoes do in game menu
#define INGAMEMENU_BUTTON_HEIGHT 36 //Altura dos botoes do in game menu
#define INGAMEMENU_BUTTON_POSX (149 + INGAMEMENU_POSX - (INGAMEMENU_BASE/2)) // Posicao X de todos os botoes
#define INGAMEMENU_BUTTON_CONTINUAR (202 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao
#define INGAMEMENU_BUTTON_RESTART (148 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do  botao
#define INGAMEMENU_BUTTON_MAINMENU (94 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao
#define INGAMEMENU_BUTTON_EXIT (40 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao

#define GAMEMENU_BUTTON_WIDTH 340 //Largura dos botoes do game menu
#define GAMEMENU_BUTTON_HEIGHT 54 //Altura dos botoes do game menu
#define GAMEMENU_BUTTON_POSX 800 // Posicao X de todos os botoes
#define GAMEMENU_BUTTON_START (MAX_Y - 340) //Posicao Y do botao
#define GAMEMENU_BUTTON_HIGHSCORES (MAX_Y - 420) //Posicao Y do  botao
#define GAMEMENU_BUTTON_CREDITS (MAX_Y - 502) //Posicao Y do botao
#define GAMEMENU_BUTTON_OPCOES (MAX_Y - 582) //Posicao Y do botao
#define GAMEMENU_BUTTON_EXIT (MAX_Y - 660) //Posicao Y do botao

#define OPTION_BUTTON_WIDTH 342 //Largura dos botoes do option menu
#define OPTION_BUTTON_HEIGHT 54 //Altura dos botoes do option menu
#define OPTION_BUTTON_VOLTAR_POSX 1258 // Posicao X do botao de voltar
#define OPTION_BUTTON_VOLTAR_POSY (MAX_Y - 716) // Posicao Y do botao de voltar
#define OPTION_DIFICULDADE_POSX 498 //Posicao X dos botoes de dificuldade
#define OPTION_RESOLUCAO_POSX 1072//Posicao X dos botoes de dificuldade
#define OPTION_BUTTON_POSY_1 (538 - FLOOR_DEPTH)//Posicao Y dos botoes 1
#define OPTION_BUTTON_POSY_2 (456 - FLOOR_DEPTH)//Posicao Y dos botoes 2
#define OPTION_BUTTON_POSY_3 (374 - FLOOR_DEPTH)//Posicao Y dos botoes 3
#define OPTION_BUTTON_POSY_4 (294 - FLOOR_DEPTH)//Posicao Y dos botoes 4

#define PLAYER_STARTPOSX 0 //Posicao X de inicio do jogador
#define PLAYER_STARTPOSY 80 //Posicao Y de inicio do jogador
#define PLAYER_STARTPOSZ -5 //Posicao Z de inicio do jogador
#define PLAYER_STARTANGLE 0 //Posicao da rotacao inicial do jogador

#define CAMERA_QTDE 5 //Quantidade de cameras no jogador
#define CAMERA_PITCH_SPEED 0.1 //Velocidade da mudanca do pitch da camera

#define CITY_SCALEMULTIPLAYER 2000 //Multiplicador para o tamanho da cidade

#define SHOWMENU_BUTTON_WIDHT 342 //Largura dos botoes dos creditos e Highscores
#define SHOWMENU_BUTTON_HEIGHT 54 //Altura dos botoes dos creditos e Highscores
#define SHOWMENU_BUTTON_POSX 1258 // Posicao X do botao de voltar
#define SHOWMENU_BUTTON_POSY (MAX_Y - 716) // Posicao Y do botao de voltar

//-------------------------

//Cria um tipo que representa uma funcao que tem como parametros void e retorna void
typedef void (*function)(void);
//-------------------------

//Cria um tipo Boolean em C
typedef enum { False = 0, True = !False } bool;
//-------------------------
//Game States Options
typedef enum {GameState,MenuState,InGameMenuState,CreditsState,OptionState,LoadingState} StateSelection;
//-------------------------

//Prototypes dos outros arquivos
//Window
void atualizaTela();
void redimensiona(int w, int h);
void configura3D();
//GameLogic
void startPause();
void endPause();
void tick(int i);
void loadGame();
void restartGame();
void fPause();
void endGame();
//Inputs
float mouseFixX(int x);
float mouseFixY(int y);
void teclado(unsigned char key, int x, int y);
void tecladoRelease(unsigned char key, int x, int y);
void specialKeysPress(int key,int x,int y);
void specialKeysRelease(int key,int x,int y);
//Desenhos
void drawRelogio(int x,int y,unsigned long int relog);
void drawNotificationSquare(int x, int y,int base,int alt, GLuint textID);
void drawFullScreen(GLuint idTextura);
void drawUFO(GLMmodel ** model, float rotation);
void drawTextHUD (int x,int y,char * str);
void drawSkyBox(int skyBoxDistance,GLuint idText);
//Textures
void load_allTextures ();
//Models
void load_allModels ();
void makeLists();
//Objects
void initPlayer(PlayerObject * o, void (*d)(float x, float y, float z,GLuint idText));
//Player
void loadPlayer(float x, float y, float z,float rotationAngle, float color[4], int CamerasQte,CameraObject * cameras, GLuint * TextId);
//Cameras
void startCameras();
//Physics
void physicsUpdate();
//Timer
void setAlarm(function F ,int remainingSeg);
void removeAlarm(int pos);
unsigned long int getTimer();
void setTimer(unsigned long int t);
void resetTimer();
void startTimer();
void pauseTimer();
void initTimer();
//Texto
void texto(void* font, char* s, float x, float y);
//Wait
void wait(int ticks,function f);
void nullFunc();
//InGameMenu
void activateInGameMenu();
void closeInGameMenu();
//States
void selectState(StateSelection selection);
//Lights
void configuraLights();
void configuraFog();
//-------------------------

// Contem as Variaveis Globais Universais utilizadas(Compartilhadas entre arquivos)
//Main
extern int RESOLUTION_WIDTH;
extern int RESOLUTION_HEIGHT;
extern bool pause;
//Texturas
extern GLuint texturas[];
extern GLuint * playerRunTex;
//Models
extern GLMmodel ** models;
extern GLuint modelLists[];
//GameLogic
extern float const tickFreq;
extern float rotationUFO;
extern bool lightON;
extern bool fogON;
extern GLenum masterLight;
//Player
extern PlayerObject player;
//Cameras
extern CameraObject * cameras;
extern int cameraAtual;
extern float cameraPitch;
//Physics
extern int fowardVariation;
extern int rotationVariation;
extern int altitudeVariation;
//InGameMenu
extern bool inGameMenuActive;
//Texto
extern const float defaultColorTexto[4];
//Lights
extern float masterLightPos[];
//-------------------------



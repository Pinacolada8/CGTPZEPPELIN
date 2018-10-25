#include "Geral.h"


bool inGameMenuActive = False;


void activateInGameMenu(){
    inGameMenuActive = True;
    startPause();
    selectState(InGameMenuState);
}

void closeInGameMenu(){
    selectState(GameState);    
    inGameMenuActive = False;    
    endPause();     
}



#include "Geral.h"

int waitTicks;
function trigger;

void waiting(int i){
    waitTicks--;
    if(waitTicks <= 0){
        (*trigger)();
    }else{
        glutTimerFunc(TICK_MSEC,waiting,1);  
    }    
}

void wait(int ticks,function f){
    waitTicks = ticks;
    trigger = f;
    glutTimerFunc(TICK_MSEC,waiting,1);
}

void nullFunc(){//Funcao que nao faz nada, utilizada para ponteiro de funcoes nulos
    
}

#include "Geral.h"

#include <stdio.h>
#include <stdlib.h>

#include "FMOD/fmod.h"//Incluindo a biblioteca de FMOD para a utilizacao de sons
#include "FMOD/fmod_errors.h"//Erros do FMOD

FMOD_SYSTEM * fmodSystem = NULL;
FMOD_RESULT result;
FMOD_SOUND * sound;

int TESTING(int argc, char** argv) {
    int loop;

    result = FMOD_System_Create(&fmodSystem);

    if (result != FMOD_OK) {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }

    result = FMOD_System_Init(fmodSystem, 512, FMOD_INIT_NORMAL, 0);
    if (result != FMOD_OK) {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }

    result = FMOD_System_CreateSound(fmodSystem, "my.mp3", FMOD_LOOP_NORMAL, 0,&sound);
    if (result != FMOD_OK) {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }

    FMOD_System_PlaySound(fmodSystem,sound,0,0,0);
    
    scanf("%i",&loop);
    
    return (EXIT_SUCCESS);
}
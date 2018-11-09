#include "Geral.h"

#include "FMOD/fmod.h"//Incluindo a biblioteca de FMOD para a utilizacao de sons
#include "FMOD/fmod_errors.h"//Erros do FMOD

#define QUANTIDADE_SONS 2 // Quantidade de sons a serem carregados
#define DEFAULT_VOLUME 0.5 //Volume Inicial


const char * pathsSounds[] = {//Local dos sons
    "GameResources/Sounds/ArcadeGame(8BIT).mp3",          //0 -- Som do Menu  
    "GameResources/Sounds/TheFatRat_ Xenogenesis.mp3",    //1 -- Som do Game      
};

FMOD_SYSTEM * fmodSystem = NULL;
FMOD_RESULT result;
FMOD_SOUND ** sounds;
FMOD_CHANNEL ** soundChannels;
FMOD_CHANNELGROUP *masterGroup,*groupA;

void FMOD_ERROR(FMOD_RESULT result){
    if (result != FMOD_OK) {
        printf("SOUND error! (%d) %s\n", result, FMOD_ErrorString(result));
    }
}

void initSoundSystem(){
    result = FMOD_System_Create(&fmodSystem);
    FMOD_ERROR(result);

    result = FMOD_System_Init(fmodSystem, 512, FMOD_INIT_NORMAL, 0);
    FMOD_ERROR(result);
    
    result = FMOD_System_CreateChannelGroup(fmodSystem,"GroupA",&groupA);
    FMOD_ERROR(result);
    
    result = FMOD_System_GetMasterChannelGroup(fmodSystem,&masterGroup);
    FMOD_ERROR(result);
    
    result = FMOD_ChannelGroup_AddGroup(masterGroup,groupA,1,0);
    FMOD_ERROR(result);
    
    
    
 
}

FMOD_SOUND * load_sound(const char path[],FMOD_MODE playMode){
    FMOD_SOUND * sound;
    result = FMOD_System_CreateSound(fmodSystem, path, playMode, 0,&sound);
    FMOD_ERROR(result);
    
    return sound;
 
}

void load_allSounds (){
    int i;
    sounds = malloc(QUANTIDADE_SONS * sizeof(FMOD_SOUND *));
    soundChannels = malloc(QUANTIDADE_SONS * sizeof(FMOD_CHANNEL *));
    for (i=0;i<QUANTIDADE_SONS;i++){      
        sounds[i] = load_sound(pathsSounds[i],FMOD_LOOP_NORMAL);
        result = FMOD_System_PlaySound(fmodSystem,sounds[i],groupA,1,&soundChannels[i]);
        FMOD_ERROR(result);
    }    
}

void playSound(int soundID, FMOD_BOOL isPaused){
    result = FMOD_Channel_SetPaused(soundChannels[soundID],isPaused);
    FMOD_ERROR(result);
    
    result = FMOD_ChannelGroup_SetVolume(groupA,DEFAULT_VOLUME);//ALTERAR
    FMOD_ERROR(result);
}

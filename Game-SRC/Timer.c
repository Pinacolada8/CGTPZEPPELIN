
#include "Geral.h"

#define SEG_MSEG 1000



//Este arquivo cria um timer, contador de segundos

unsigned long int timerTime = 0;
int timerRunning = 0;

int alarms;//Quantidade de alarmes de funcoes
unsigned long int * alarmTime;//Tempo que a funcao sera chamada
function * func;//Array de ponteiro de funcoes

void timer(int i);

void initTimer(){
    timerTime = 0;
    free(alarmTime);
    free(func);    
    alarms = 0;//Quantidade de alarmes de funcoes
    alarmTime = malloc(1*sizeof(long int));//Tempo que a funcao sera chamada
    func = malloc(1*sizeof(function));//Array de ponteiro de funcoes    
}

void setAlarm(function F ,int remainingSeg){    
    alarms++;    
    alarmTime=realloc(alarmTime,alarms);
    func=realloc(func,alarms);
    func[alarms-1]= F;
    alarmTime[alarms-1] = timerTime + remainingSeg;      
}

void removeAlarm(int pos){
    int i;
    for(i=pos;i<alarms-1;i++){
        alarmTime[i]=alarmTime[i+1];
        func[i]=func[i+1];
    }
    alarms--;
}

unsigned long int getTimer(){
    return timerTime;
}

void setTimer(unsigned long int t){
    timerTime = t;
}

void resetTimer(){
    pauseTimer();
    while(alarms != 0){
        removeAlarm(alarms-1);
    }
    timerTime = 0;    
}

void startTimer(){
    timerRunning = 1;
    glutTimerFunc(SEG_MSEG,timer,1);
}

void pauseTimer(){
    timerRunning = 0;
}

void timer(int i){   
    if(timerRunning != 0){//Para e continua o timer
        timerTime++;        
        
        for(i=0;i<alarms;i++){
            if (alarmTime[i] == timerTime){
                (*func[i])();                 
                removeAlarm(i);
            }
        }
        
        glutTimerFunc(SEG_MSEG,timer,1);
    }else{
        return;
    }
}
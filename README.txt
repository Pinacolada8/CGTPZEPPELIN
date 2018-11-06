-> Leia o -----Instrucoes------.txt Para saber como compilar o Projeto. <-

- > CASO AO COMPILAR APARECA ALGUM PROBLEMA RELATIVO A FALTA DE BIBLIOTECAS, TODAS AS BIBLIOTECAS UTILIZADAS NO PROJETO ESTAO DENTRO DA PASTA "GameResources" <-

- > A Biblioteca FMOD foi utilizada, caso encontre erros na execução relacionados a fmod, instale-a pelo site "https://www.fmod.com/download" (OBS:É NECESSARIO ESTAR LOGADO PARA BAIXAR) 
	Caso necessite de ajuda para instalar em linux derivados de debian olhe este site "https://wiki.debian.org/FMOD", NAO E NECESSARIO INSTALAR O FMOD STUDIO <-

-> Alguns computadores utilizando linux apresentam problemas de compilação na soucecode da SOIL, caso tenha este problema utilize outro computador/sistem Operacional ou 
	altere a importacao da soil de (#include "SOIL/SOIL.h") para (#include <SOIL/SOIL.h>), nos sequintes arquivos (Geral.h),(GLM/glmimg.c). <-
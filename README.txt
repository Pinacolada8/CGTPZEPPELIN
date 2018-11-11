-> Leia o -----Instrucoes------.txt Para saber como compilar o Projeto. <-

-> CASO AO COMPILAR APARECA ALGUM PROBLEMA RELATIVO A FALTA DE BIBLIOTECAS, TODAS AS BIBLIOTECAS UTILIZADAS NO PROJETO ESTAO DENTRO DA PASTA "GameResources" <-
-> O Progama Utiliza supostamente as bibliotecas locais, caso apareça um aviso da falta de bibliotecas, me informe por favor <-

-> A Biblioteca FMOD foi utilizada, caso encontre erros na execução relacionados a fmod, instale-a pelo site "https://www.fmod.com/download" (OBS:É NECESSARIO ESTAR LOGADO PARA BAIXAR) 
	Caso necessite de ajuda para instalar em linux derivados de debian olhe este site "https://wiki.debian.org/FMOD", NAO E NECESSARIO INSTALAR O FMOD STUDIO <-

-> Alguns computadores utilizando linux apresentam problemas de compilação na soucecode da SOIL, caso tenha este problema utilize outro computador/sistem Operacional ou 
	altere a importacao da soil de (#include "SOIL/SOIL.h") para (#include <SOIL/SOIL.h>), nos sequintes arquivos (Geral.h),(GLM/glmimg.c). <-

-> Implementações:
	-BASICO (COMPLETO)
	-NOITE/DIA (Letra 'N' troca)
	-SKYBOX (Dia & Noite)
	-FORMATO OBJ (Carregado com textura e material)
	-FOG (Letra 'F' ativa/desativa)
	-A CAMERA 2 PODE ALTERAR OLHAR PARA CIMA E PARA BAIXO ('+' e '-' para olhar)
	-MENU COMPLETO
	-TELA DE LOADING (Carregamento dos OBJs)
	-UTILIZADO DISPLAY LIST (Teve um maior desempenho que VBOs)
	-HUD DE COORDENADAS E ROTAÇÃO (Plano 2d em frente a tela)
	-HUD TIMER (Representa um timer no tempo que passou dentro do jogo, representado em hud)
	-IN-GAME-MENU (Menu ingame ao apertar a tecla ESC, permitindo voltar ao menu, continuar no game, ou sair do jogo)
	-MUSICA DE MENU & INGAME (Musica diferente no menu e no jogo) (Letra 'M' Muta)	
	-BOOST DE VELOCIDADE (Aperte e segure 'shift' antes de comecar a se mover, para se mover mais rapido)
		<-
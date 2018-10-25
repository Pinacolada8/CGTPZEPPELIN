@ECHO OFF
title Compilar
color 0a

ECHO Compilando...

SET Arquivos=GameSRC/*

gcc -o Start %Arquivos% -lfreeglut -lglu32 -lglew32 -lSOIL -lopengl32 -lm -Wall -g
pause
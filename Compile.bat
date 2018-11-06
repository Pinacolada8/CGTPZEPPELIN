@ECHO OFF
title Compilar
color 0a

ECHO Compilando...

SET Arquivos=Game-SRC/*.c Game-SRC/SOIL/*.c Game-SRC/GLM/*.c

gcc -o Start %Arquivos% -lfreeglut -lglu32 -lglew32 -lSOIL -lopengl32 -lm -lfmod

ECHO FIM(COMPILADO)
pause
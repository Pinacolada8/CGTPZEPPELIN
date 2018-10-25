#include "Geral.h"

const float defaultColorTexto[4] = {0,0,0,1};

void texto(void* font, char* s, float x, float y) {
  unsigned int i;
  glRasterPos2f(x, y);

  for (i = 0; i < strlen (s); i++) {
     glutBitmapCharacter(font, s[i]);
  }
}

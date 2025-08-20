#ifndef TEXT_H
#define TEXT_H

#include <citro2D.h>

// extern float size;
// extern C2D_TextBuf g_staticBuf;
extern C2D_Font font[2];
extern C2D_TextBuf scramble_Buf;
extern C2D_TextBuf Timer_Buf;

extern C2D_TextBuf solves_Buf[5];
extern C2D_TextBuf solveAverage_Buf;
extern C2D_TextBuf sign_buf;

void initText();
void addText(const char *toPrint, C2D_Text *gtext, C2D_TextBuf g_staticBuf, int whatFont);
void sceneRender(C2D_Text *gtext, float x, float y, float size, C2D_TextBuf g_staticBuf);

#endif
#include "main.h"
#include "text.h"
#include "touch.h"
#include "util.h"

C2D_Font font[2];

C2D_TextBuf scramble_Buf;
C2D_TextBuf Timer_Buf;

C2D_TextBuf solves_Buf[5];
C2D_TextBuf solveAverage_Buf;
C2D_TextBuf sign_buf;

void initText() {
    font[0] = C2D_FontLoad("romfs:/monaco.bcfntx");
    font[1] = C2D_FontLoad("romfs:/arial.bcfntx");


    scramble_Buf = C2D_TextBufNew(21);
    Timer_Buf = C2D_TextBufNew(8);
    solveAverage_Buf = C2D_TextBufNew(15);
    sign_buf = C2D_TextBufNew(30);

    int iter;
	for (iter = 0; iter < 5; iter++) {
		solves_Buf[iter] = C2D_TextBufNew(8);
		sprintf(stringifiedTime, "%.2f", aof[iter]);
		addText(stringifiedTime, &solves[iter], solves_Buf[iter], 1);
	}

}

void addText(const char *toPrint, C2D_Text* gtext, C2D_TextBuf g_staticBuf, int whatFont) {
    C2D_TextBufClear(g_staticBuf);
    C2D_TextFontParse(gtext, font[whatFont], g_staticBuf, toPrint);
	C2D_TextOptimize(gtext);
}

void sceneRender(C2D_Text *gtext, float x, float y, float size, C2D_TextBuf g_staticBuf) {
    if (x < 0) {
        x = BOT_SCREEN_WIDTH/2 + x;
        C2D_DrawText(gtext, C2D_AtBaseline, x, y, 0, size, size);
    }
    else {
        C2D_DrawText(gtext, C2D_AtBaseline, x, y, 0, size, size);
    }
}

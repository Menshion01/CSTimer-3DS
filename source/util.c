#include "util.h"
#include "main.h"
#include "text.h"

u32 clrWhite;
u32 clrGray;
u32 clrBlue;
u32 clrPink;
u32 clrGreen;

void initiate() {
    romfsInit();
	cfguInit(); // Allow C2D_FontLoadSystem to work
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    //consoleInit(GFX_TOP, NULL);
}

void initColours() {
    clrWhite = C2D_Color32(255, 255, 255, 255);
    clrGray = C2D_Color32(220, 220, 220, 255);
    clrBlue  = C2D_Color32(40, 100, 255, 255);
    clrPink = C2D_Color32(255, 189, 189, 255);
    clrGreen = C2D_Color32(228, 255, 173, 255);
}

void end() {

    int murderint;
    for (murderint = 0; murderint < 5; murderint++)
    {
        C2D_TextBufDelete(solves_Buf[murderint]);
    }

    C2D_TextBufDelete(scramble_Buf);
    C2D_TextBufDelete(Timer_Buf);
    C2D_TextBufDelete(solveAverage_Buf);
    C2D_TextBufDelete(sign_buf);

    C2D_FontFree(font[0]);
    C2D_FontFree(font[1]);

    C2D_Fini();
    C3D_Fini();
    gfxExit();
}
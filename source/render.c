#include <citro2d.h>

#include "main.h"
#include "render.h"
#include "touch.h"
#include "util.h"
#include "text.h"
#include "ui.h"
#include "time.h"


void render(C3D_RenderTarget *bot, C3D_RenderTarget *top) {

    // Initalise rendering
    C3D_FrameEnd(0); // Render the scene
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(bot);
    C2D_SceneBegin(top);
    
    C2D_TargetClear(bot, clrPink);
    C2D_TargetClear(top, clrGreen);
    C2D_DrawRectSolid(0, 0, 0, 88, SCREEN_HEIGHT, clrGray);
    C2D_DrawRectSolid(0, 0, 0, 85, SCREEN_HEIGHT, clrPink);
    C2D_DrawRectSolid(0, 0, 0, SCREEN_WIDTH, 54, clrGray);
    C2D_DrawRectSolid(0, 0, 0, SCREEN_WIDTH, 50, clrPink);
    //C2D_DrawRectSolid(RectX, RectY, 0, 100, 50, clrWhite);

    //When touching bottom screen turn it white
    if (touch.px > 0) {
        C2D_TargetClear(bot, clrWhite);
    }
    
    //C2D_DrawRectSolid(16, (120 + 20 * solutionNum), 0, 50, 20, clrGray); Block UI
    C2D_DrawRectSolid(10, (120 + 20 * solutionNum), 0, 5, 20, clrWhite);

    sceneRender(&g_scramble, 30, 40, 1.2f, scramble_Buf); // Render Scramble
    sceneRender(&g_timer, 110, 150, 4.0f, Timer_Buf);     // Render Timer
    sceneRender(&solveAverage, 160, 200, 1.2f, solveAverage_Buf); // Render Average
    sceneRender(&signature, 335, 232, 0.5f, sign_buf);    // Render My name

    //Render each solve time
    int renderint;
    for (renderint = 0; renderint < 5; renderint++) {
        sceneRender(&solves[renderint], 16, (140 + 20*renderint), 1.0f, solves_Buf[renderint]);
    }
    //sceneRender(&solves[1], 30, 140, 0.8f, solves_Buf[1]);
    
    C3D_FrameEnd(0);

}
#ifndef MAIN_H
#define MAIN_H

#include <citro2d.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "touch.h"
#include "util.h"
#include "text.h"
#include "letGen.h"
#include "ui.h"
#include "render.h"
#include "time.h"

extern bool last_touch_state;
extern bool stopwatch_running;
extern bool waiting_to_start;
extern char *currentScramble;
extern float aof[];
extern float averageVal;
extern int solutionNum;

extern C2D_TextBuf scramble_Buf;
extern C2D_TextBuf Timer_Buf;

extern C2D_TextBuf solves_Buf[5];
extern C2D_TextBuf solveAverage_Buf;
extern C2D_TextBuf sign_buf;

extern char stringifiedTime[20];

extern u32 kDown;

#endif
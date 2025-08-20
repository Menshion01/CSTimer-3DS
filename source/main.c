#include "main.h"

char* currentScramble;
int solutionNum = 0;

char stringifiedTime[20];

int main() {
	
	initiate();
	initColours();
	initText();

	//Cube scramble Generator Seed input
	srand(time(NULL));

	currentScramble = cubeMoves();
	
	//Add the scramble to the text
	addText(currentScramble, &g_scramble, scramble_Buf, 0);
	addText("By Mason", &signature, sign_buf, 0);

	// Create screen(s)
	C3D_RenderTarget *bot = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	
	while (aptMainLoop()) {
		hidScanInput();
		updateTouch(); 
		
		stopwatchFunction();
		char elapsed_time[20];
		sprintf(elapsed_time, "%.2f", get_elapsed_time());
		addText(elapsed_time, &g_timer, Timer_Buf, 1);
		
		char result[40];
		snprintf(result, sizeof(result), "ao5: %.2f", averageVal);
		
		addText(result, &solveAverage, solveAverage_Buf, 1);
		
		// Check if a key is down, if it's start then close the app
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;
		else buttonPress(kDown); //Dpad press => solutionNum logic 
		
		render(bot, top);
	}

	end();
	return 0;
}

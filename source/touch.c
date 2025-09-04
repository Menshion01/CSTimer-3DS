#include "main.h"
#include "touch.h"
#include "time.h"
#include "main.h"
#include "text.h"

touchPosition touch;

void updateTouch() {
    hidTouchRead(&touch);
}


bool buttonPress(u32 buttonPressed) {

    if (buttonPressed & KEY_DRIGHT || buttonPressed & KEY_DDOWN)
        solutionNum++;
    if (buttonPressed & KEY_DLEFT || buttonPressed & KEY_DUP)
        solutionNum--;
    
    if (buttonPressed & KEY_B) {
        int inQuestion = solutionNum;
        
        if (stopwatch_running) { //DNF function while timer is running
            solList[inQuestion] = -1;
            currentScramble = cubeMoves(); // New alg
            addText(currentScramble, &g_scramble, scramble_Buf, 0);
            
            addText("DNF", &solves[solutionNum], solves_Buf[solutionNum], 0);
            stop_stopwatch();
            stopwatch_running = false;
            collect_average();
        } else { //DNF function will timer is stopped
            if (inQuestion == 0) inQuestion = 5;
            solList[inQuestion-1] = -1;
            addText("DNF", &solves[inQuestion-1], solves_Buf[inQuestion-1], 0);
            collect_average();
        }
    }
    else if (buttonPressed & KEY_X) {
        if (!stopwatch_running) {
            int inQuestion = solutionNum;
            if (inQuestion == 0) inQuestion = 5; 
            solList[inQuestion-1] += 2;
            sprintf(stringifiedTime, "%.2f", solList[inQuestion-1]);
            addText(stringifiedTime, &solves[inQuestion-1], solves_Buf[inQuestion-1], 1);
            collect_average();
        }
    }
    

    if (solutionNum == -1)
        solutionNum = 4;
    if (solutionNum == 5)
        solutionNum = 0;

    return 0.0;
}


// // Point to rectangle collusion script
// bool collusion(float x, float y, float width, float height, float ox, float oy) {
//     // If specified as 0, default to mouse position
//     if (!x) x = touch.px;
//     if (!y) y = touch.py;

//     if (ox <= x && x <= ox+width) {

//         if (oy <= y && y <= oy + height) {
//             return true;
//         }
//     }
//     return false;
// }
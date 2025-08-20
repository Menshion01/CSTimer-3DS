#include "main.h"
#include "touch.h"

touchPosition touch;

void updateTouch() {
    hidTouchRead(&touch);
}


bool buttonPress(u32 buttonPressed) {

    if (buttonPressed & KEY_DRIGHT || buttonPressed & KEY_DDOWN)
        solutionNum++;
    if (buttonPressed & KEY_DLEFT || buttonPressed & KEY_DUP)
        solutionNum--;
    

    if (solutionNum == -1)
        solutionNum = 4;
    if (solutionNum == 5)
        solutionNum = 0;

    return 0;
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
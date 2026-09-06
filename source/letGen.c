#include "main.h"
#include "letGen.h"

// code based on https://github.com/alexcoplan/scrambler

#define SCRAMBLE_LENGTH 20
static char jamble[SCRAMBLE_LENGTH*2+1];
char modifers[] = {'\'', '2'};
char moves[] = {'L', 'R', 'U', 'D', 'F', 'B'};
// to get planes, we divide side index by 2
// 0: x, 1: y, 2: z

char side;
int planeBuffer[2]; // there should only be at max 2 buffered
int planesBuffered = 0;
int randomValue = 0;

int i = 0;

char *cubeMoves() {
    for (i = 0; i < SCRAMBLE_LENGTH; i++) {
        if (planesBuffered == 0) {
            randomValue = rand() % 6;
            side = moves[randomValue];
        }
        else if (planesBuffered == 1) {
            randomValue = rand() % 6;
            if (randomValue == planeBuffer[0]) {
                // in the original they used splice to remove the previously picked side so it doesnt get picked again, but i can't do that in C easily
                // it's a 1/36 or roughly 2.7% chance it picks the same side again
                randomValue = rand() % 6;
            }

            side = moves[randomValue];

            if (planeBuffer[0] / 2 != randomValue / 2) {
                planesBuffered = 0;
            }
        }
        else {
            randomValue = rand() % 6;
            if (randomValue/2 == planeBuffer[0]/2) { // both sides in the buffer should result in the same plane
                // 4/36: ~11.1% for it to choose the same plane again
                do {
                    randomValue = rand() % 6;
                } while (randomValue/2 == planeBuffer[0]/2);
            }

            side = moves[randomValue];

            planesBuffered = 0;
        }
        planeBuffer[planesBuffered] = randomValue;
        planesBuffered += 1;
        jamble[i] = side;

        randomValue = rand() % 3;
        if (randomValue > 0) {
            i += 1;
            jamble[i] = modifers[randomValue-1];
        }
    }
    jamble[SCRAMBLE_LENGTH] = '\0'; // Null-terminate the string

    return jamble;
}

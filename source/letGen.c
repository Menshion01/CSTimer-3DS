#include "main.h"
#include "letGen.h"

int i = 0;
char moves[] = {'U', 'D', 'F', 'B', 'L', 'R'};
static char jamble[41];

char *cubeMoves() {
    
    for (i = 0; i < 20; i++) {
        char move = moves[rand() % 6];
        // int randNum = rand() % 6; // Random index from 0 to 5
        
        if (move == jamble[i - 1] && jamble[i - 1] != 2) {
            jamble[i] = '2';
        }
        else {
            jamble[i] = move;
        }
    }
    
    jamble[20] = '\0'; // Null-terminate the string
    
    return jamble;
}
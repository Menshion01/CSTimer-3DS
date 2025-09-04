#include "time.h"
#include <sys/time.h>
#include "main.h"
#include "text.h"

struct timeval start_time;
struct timeval end_time;
int running = 0;
float averageVal = 0;
float solList[] = {0, 0, 0, 0, 0};

bool last_touch_state = false;
bool stopwatch_running = false;
bool waiting_to_start = false;

void start_stopwatch(void) {
    gettimeofday(&start_time, NULL);
    running = 1;
}

float stop_stopwatch(void) {
    if (running) {
        gettimeofday(&end_time, NULL);
        running = 0;

        double start_seconds = start_time.tv_sec + start_time.tv_usec / 1e6;
        double end_seconds = end_time.tv_sec + end_time.tv_usec / 1e6;

        solutionNum++;
        return end_seconds - start_seconds;
    }
    solutionNum++;
    return 0.0;
}

void reset_stopwatch(void) {
    start_time.tv_sec = 0;
    start_time.tv_usec = 0;
    end_time.tv_sec = 0;
    end_time.tv_usec = 0;
    running = 0;
}

float get_elapsed_time(void) {
    if (running) {
        struct timeval now;
        gettimeofday(&now, NULL);
        double start_seconds = start_time.tv_sec + start_time.tv_usec / 1e6;
        double now_seconds = now.tv_sec + now.tv_usec / 1e6;
        return now_seconds - start_seconds;
    }
    else {
        double start_seconds = start_time.tv_sec + start_time.tv_usec / 1e6;
        double end_seconds = end_time.tv_sec + end_time.tv_usec / 1e6;
        return end_seconds - start_seconds;
    }
}

void collect_average() {
    float min = -2;
    float max = -2;
    int i = 0;
    int validNumCount = 0;
    int DNFcount = 0;

    for (i = 0; i < 5; i++) {
        if (min == -2 && solList[i] > 0) min = solList[i]; 
        if (max == -2 && solList[i] > 0) max = solList[i];
        // Start min and max at a solve at the start, if current solve being checked isn't completed or a DNF don't pick it

        if (solList[i] != 0.00) {
            if (solList[i] == -1) {
                max = -1; //Set DNF to the longest time
                DNFcount ++;
            }
            else if (solList[i] > max && max != -1) max = solList[i];
            else if (solList[i] < min && solList[i] != -1) min = solList[i];
            validNumCount ++;
        }
    }

    if (validNumCount < 5 || DNFcount > 1) averageVal = 0.00;
    else averageVal = ((solList[0] + solList[1] + solList[2] + solList[3] + solList[4]) - max - min) / 3;
    //If Max is a dnf (-1) - -1 equals +1; therefor canceling it out as its function is

    // sprintf(stringifiedTime, "%.2f", (solList[0] + solList[1] + solList[2] + solList[3] + solList[4]) - max - min);
    // addText(stringifiedTime, &g_scramble, scramble_Buf, 1); //Angry test box debug option
}


void stopwatchFunction() {
    //Bottom screen stopwatch checker
    if (touch.px > 0 && !last_touch_state) {
        last_touch_state = true;
        
        if (!stopwatch_running) {
            waiting_to_start = true;
        }
        else if (get_elapsed_time() > 0.01) {

            // stop stopwatch
            solList[solutionNum] = get_elapsed_time();
            currentScramble = cubeMoves(); // New alg
            addText(currentScramble, &g_scramble, scramble_Buf, 0);
            
            sprintf(stringifiedTime, "%.2f", solList[solutionNum]);
            addText(stringifiedTime, &solves[solutionNum], solves_Buf[solutionNum], 1);
            collect_average();

            if (solutionNum == 5){ //SolutionNum overflowed
                solutionNum = 0;
            }

            stop_stopwatch();
            stopwatch_running = false;
            
        }
    }
    
    // Touch just ended
    if (touch.px == 0 && last_touch_state) {
        last_touch_state = 0;
        
        if (waiting_to_start) {
            start_stopwatch();
            stopwatch_running = true;
            waiting_to_start = 0;
        }
    }
}
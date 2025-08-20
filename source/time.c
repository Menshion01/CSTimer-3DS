#include "time.h"
#include <sys/time.h>
#include "main.h"
#include "text.h"

struct timeval start_time;
struct timeval end_time;
int running = 0;
float averageVal = 0;
float aof[] = {0, 0, 0, 0, 0};

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

        return end_seconds - start_seconds;
    }
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

void stopwatchFunction() {
    //Bottom screen stopwatch checker
    if (touch.px > 0 && !last_touch_state) {
        last_touch_state = true;
        
        if (!stopwatch_running) {
            waiting_to_start = true;
        }
        else if (get_elapsed_time() > 0.01) {
            
            // stop stopwatch and collect average
            aof[solutionNum] = stop_stopwatch();
            currentScramble = cubeMoves(); // New alg
            addText(currentScramble, &g_scramble, scramble_Buf, 0);
            
            int addtextint;
            for (addtextint = 0; addtextint < 5; addtextint++) {
                sprintf(stringifiedTime, "%.2f", aof[addtextint]);
                addText(stringifiedTime, &solves[addtextint], solves_Buf[addtextint], 1);
            }
            
            solutionNum++;
            averageVal = (aof[0] + aof[1] + aof[2] + aof[3] + aof[4]) / 5;
            
            if (solutionNum == 5){ //SolutionNum overflowed
                solutionNum = 0;
            }

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
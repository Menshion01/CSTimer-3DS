#ifndef TIME_H
#define TIME_H

#include <time.h>
#include <stdbool.h>

extern float averageVal;
extern float solList[];

extern bool last_touch_state;
extern bool stopwatch_running;
extern bool waiting_to_start;

extern void start_stopwatch(void);

extern float stop_stopwatch(void);

extern void reset_stopwatch(void);

extern float get_elapsed_time(void);


extern void collect_average();


extern void stopwatchFunction(void);

#endif

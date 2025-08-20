#ifndef TIME_H
#define TIME_H

#include <time.h>

extern float averageVal;
extern float aof[];

extern void start_stopwatch(void);

extern float stop_stopwatch(void);

extern void reset_stopwatch(void);

extern float get_elapsed_time(void);

extern void stopwatchFunction(void);

#endif

#ifndef TOUCH_H
#define TOUCH_H

#include <3ds.h>
#include <citro2d.h>

extern touchPosition touch; // Declare global variable

void updateTouch(); // Function to update the global touch
bool buttonPress(u32 buttonPressed);

//bool collusion(float x, float y, float width, float height, float ox, float oy);

#endif
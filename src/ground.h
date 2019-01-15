#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED

#include "ball.h"

typedef struct {
    int width;
    int height;
    int top_line;
    int ground_line;

} GROUND;

void ground_paint(GROUND *ground);

int ground_hit(GROUND ground, BALL *ball);

#endif // GROUND_H_INCLUDED

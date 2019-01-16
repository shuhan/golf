#ifndef HOLE_H_INCLUDED
#define HOLE_H_INCLUDED

#include "ball.h"

typedef struct {
    int x;
    int y;
    int width;
    int height;
} HOLE;

void hole_paint(HOLE *hole);

int hole_hit(HOLE hole, BALL *ball);

#endif // HOLE_H_INCLUDED

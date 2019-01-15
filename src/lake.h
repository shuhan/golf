#ifndef LAKE_H_INCLUDED
#define LAKE_H_INCLUDED

#include "ball.h"

typedef struct {

    int x;
    int y;
    int width;
    int height;

} LAKE;

void lake_paint(LAKE *lake);

int lake_hit(LAKE lake, BALL *ball);

#endif // LAKE_H_INCLUDED

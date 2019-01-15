#ifndef HILL_H_INCLUDED
#define HILL_H_INCLUDED

#include "common.h"
#include "ball.h"

typedef struct {
    int x;
    int y;
    int radius;
    int height;
    float peak_distance;

    GAMETRIANGLE peaks[2];

} HILL;

void hill_bound(HILL *hill);

void hill_paint(HILL *hill);

int hill_hit(HILL hill, BALL *ball);

#endif // HILL_H_INCLUDED

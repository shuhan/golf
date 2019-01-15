#ifndef DUNE_H_INCLUDED
#define DUNE_H_INCLUDED

#include "ball.h"

typedef struct {

    int x;
    int y;
    int width;
    int height;

} DUNE;

void dune_paint(DUNE *dune);

int dune_hit(DUNE dune, BALL *ball);

#endif // DUNE_H_INCLUDED

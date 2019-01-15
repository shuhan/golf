#include "dune.h"
#include <graphics_lib.h>

/**
 *  Using pointer just to maintain the style, some paint function requires pointer
 */
void dune_paint(DUNE *dune) {
    //Main pool
    filled_ellipse(dune->x, dune->y, dune->width, dune->height, SAND);
    //Mini pool
    filled_ellipse(dune->x - (dune->width * 2)/3, dune->y - (dune->height * 2)/3, dune->width / 2, dune->height / 2, SAND);
}

int dune_hit(DUNE dune, BALL *ball) {
    return ball->shape.centre.x > dune.x - dune.width && ball->shape.centre.x < dune.x + dune.width && ball->shape.centre.y + ball->shape.radius >= dune.y;
}

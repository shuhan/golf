#include "hole.h"
#include <graphics_lib.h>

void hole_paint(HOLE *hole) {
    filled_ellipse(hole->x, hole->y, hole->width, hole->height, BLACK);
}

int hole_hit(HOLE hole, BALL *ball) {
    int res = ball->shape.centre.x > hole.x - hole.width && ball->shape.centre.x < hole.x + hole.width && ball->shape.centre.y + ball->shape.radius >= hole.y;
    if(res) ball->lost = 1;
    return res;
}

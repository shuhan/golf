#include "hill.h"
#include <graphics_lib.h>

void hill_bound(HILL *hill) {

    GAMETRIANGLE t0 = {{hill->x - hill->radius, hill->y}, {hill->x, hill->y - hill->height}, {hill->x + hill->radius, hill->y}};
    hill->peaks[0] = t0;
    GAMETRIANGLE t1 = {{hill->x - (hill->radius * (1 - hill->peak_distance)), hill->y}, {hill->x + (hill->radius * hill->peak_distance), hill->y - hill->height}, {hill->x + (hill->radius * (1 + hill->peak_distance)), hill->y}};
    hill->peaks[1] = t1;
}

void hill_paint(HILL *hill) {

    hill_bound(hill);

    filled_gametriangle(hill->peaks[0], DIRT);
    filled_gametriangle(hill->peaks[1], DARKDIRT);

}

int hill_hit(HILL hill, BALL *ball) {
    int retval = hit_gametriangle(hill.peaks[0], ball->shape) || hit_gametriangle(hill.peaks[1], ball->shape);

    if(retval) {
        ball->horizontal_speed *= -1 * (1 - HILL_LOSS);
    }
    //With first pace
    if(ball->shape.centre.x > hill.x - hill.radius && ball->shape.centre.x < hill.x + hill.radius && abs(ball->horizontal_speed) < HILL_CONSUME_THREASHOLD) {
        ball->state = BALL_LOST;
        ball->horizontal_speed = 0;
        ball->vertical_speed = 0;
    }

    return retval;
}

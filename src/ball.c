#include "ball.h"
#include <graphics_lib.h>

void ball_update(BALL *ball) {

}

void ball_paint(BALL *ball) {
    if(ball->state != BALL_LOST && ball->state != BALL_IN_HOLE)
        filled_gamecircle(ball->shape, WHITE);
    setcolor(BLACK);
    circle(ball->shape.centre.x, ball->shape.centre.y, ball->shape.radius, 1);
}

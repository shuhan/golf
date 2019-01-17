#include "lake.h"
#include <graphics_lib.h>
#include "ball.h"

void lake_paint(LAKE *lake) {
    //Main pool
    filled_ellipse(lake->x, lake->y, lake->width, lake->height, WATER);
    //Mini pool
    filled_ellipse(lake->x + (lake->width * 2)/3, lake->y + (lake->height * 2)/3, lake->width / 2, lake->height / 2, WATER);
}

int lake_hit(LAKE lake, BALL *ball) {
    int res = ball->shape.centre.x > lake.x - lake.width && ball->shape.centre.x < lake.x + lake.width && ball->shape.centre.y + ball->shape.radius >= lake.y;
    if(res) {
        ball->state = BALL_LOST;
        ball->horizontal_speed  = 0;
        ball->vertical_speed    = 0;
    }
    return res;
}

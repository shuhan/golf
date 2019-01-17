#include "ground.h"
#include <graphics_lib.h>

void ground_paint(GROUND *ground) {

    filled_rectangle(0, ground->top_line, ground->width, ground->height, GRASS);
}

int ground_hit(GROUND ground, BALL *ball) {

    int retval = ball->shape.centre.y + ball->shape.radius >= ground.ground_line;

    if(retval) {
        //Ball on/hit ground && ball was in flight
        if(ball->state == BALL_IN_FLIGHT) {
            //Calculate bounce
            ball->vertical_speed    *= -1 * (1 - GROUND_LOSS);
            ball->vertical_speed    -= GRAVITY_CONSTANT;
        }

        if(ball->state == BALL_ON_SAND) {
            ball->state = BALL_ON_GROUND;
        }

        if(ball->vertical_speed <= 0) {
            ball->vertical_speed = 0;
            ball->state = BALL_ON_GROUND;       //Ground test shall be done first before any other hit test as ground also includes dune and lake
        }

        if(ball->shape.centre.x < 0 || ball->shape.centre.x > ground.width) {   //Ball left the window
            ball->state = BALL_LOST;
            ball->horizontal_speed  = 0;
            ball->vertical_speed    = 0;
        }
    }

    return retval;
}

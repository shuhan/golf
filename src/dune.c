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
    int retval = ball->shape.centre.x > dune.x - dune.width && ball->shape.centre.x < dune.x + dune.width && ball->shape.centre.y + ball->shape.radius >= dune.y;

    if(retval) {
        //Ball on/hit ground && ball was in flight
        if(ball->state == BALL_IN_FLIGHT) {
            //Calculate bounce
            ball->vertical_speed    *= -1 * (1 - SAND_LOSS);
            ball->vertical_speed    -= GRAVITY_CONSTANT;
        }

        if(ball->state == BALL_ON_GROUND) {
            ball->state = BALL_ON_SAND;
        }

        if(ball->vertical_speed <= 0) {
            ball->vertical_speed = 0;
            ball->state = BALL_ON_SAND;
        }
    }

    return retval;
}

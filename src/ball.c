#include "ball.h"
#include <graphics_lib.h>
#include <math.h>

void ball_hit(BALL *ball, float speed, float angle) {
    float angle_rad = (M_PI/180) * angle;
    ball->state = BALL_IN_FLIGHT;
    ball->horizontal_speed = speed * cos(angle_rad);
    ball->vertical_speed = speed * sin(angle_rad);
}

int ball_update(BALL *ball, GAMEWEATHER weather, float influence_rate) {

    if(ball->delay_counter > 9) {

        ball->delay_counter = 0;

        if(ball->horizontal_speed != 0) {
            ball->shape.centre.x += ball->horizontal_speed;
        }

        if(ball->vertical_speed != 0) {
            ball->shape.centre.y -= ball->vertical_speed;       //Vertical speed in upward direction require y to reduce
        }

        if(ball->state == BALL_IN_FLIGHT) {
            ball->horizontal_speed  *= (1 - AIR_LOSS);
            ball->horizontal_speed  += weather.airspeed * weather.direction * influence_rate;
            ball->vertical_speed    *= (1 - AIR_LOSS);
            ball->vertical_speed    -= GRAVITY_CONSTANT;        //Gravity constant is minus because we assume upward direction is positive
        } else if(ball->state == BALL_ON_GROUND) {
            ball->horizontal_speed *= (1 - GROUND_LOSS);
        } else if(ball->state == BALL_ON_SAND) {
            ball->horizontal_speed *= (1 - SAND_LOSS);
        }

        if(ball->horizontal_speed > -1 && ball->horizontal_speed < 1) ball->horizontal_speed = 0;
        if(ball->vertical_speed > -1 && ball->vertical_speed < 1) ball->vertical_speed = 0;

        //Once ball stops, call the ball stopped function
        if(ball->state != BALL_STATIC &&
           ball->state != BALL_IN_FLIGHT &&
           ball->stop_executed == 0 &&
           ball->horizontal_speed == 0 &&
           ball->vertical_speed == 0) {
            if(ball->on_stop) ball->on_stop(*ball);
            ball->stop_executed = 1;
        }

        if(ball->horizontal_speed != 0 || ball->vertical_speed != 0) {
            ball->stop_executed = 0;
        }

        return 1;
    } else {
        ball->delay_counter++;
        return 0;
    }
}

void ball_paint(BALL *ball) {
    if(ball->state != BALL_LOST && ball->state != BALL_IN_HOLE) {
        filled_gamecircle(ball->shape, WHITE);
        setcolor(BLACK);
        circle(ball->shape.centre.x, ball->shape.centre.y, ball->shape.radius, 1);
    }
}

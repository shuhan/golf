#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "common.h"
#include "weather.h"

#define BALL_STATIC         0
#define BALL_IN_FLIGHT      1
#define BALL_ON_GROUND      2
#define BALL_ON_SAND        3
#define BALL_IN_HOLE        4
#define BALL_LOST           5

typedef struct {
    GAMECIRCLE  shape;              //Shape of the ball
    unsigned    state;              //Ball states IN_FLIGHT, ON_GROUND, ON_SAND, LOST
    void        (*on_stop)(BALL);   //On activation event
                                    //Direction is expressed in term of horizontal and vertical speed
    float       horizontal_speed;   //In m/s (Horizontal Portion of the speed)
    float       vertical_speed;     //In m/s (Vertical Portion of the speed)

    char        delay_counter;
} BALL;

void ball_hit(BALL *ball, float speed, float angle);

/**
 *  Calculate next position and gravity effect, wind effect (Only if in flight), friction (If on Sand or Ground) etc
 */
int ball_update(BALL *ball, GAMEWEATHER weather, float influence_rate);

void ball_paint(BALL *ball);


#endif // BALL_H_INCLUDED

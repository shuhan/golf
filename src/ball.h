#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "common.h"

#define BALL_STATIC         0
#define BALL_IN_FLIGHT      1
#define BALL_ON_GROUND      2
#define BALL_ON_SAND        3
#define BALL_IN_HOLE        4
#define BALL_LOST           5


typedef struct {
    GAMECIRCLE  shape;          //Shape of the ball
    unsigned    state;          //Ball states IN_FLIGHT, ON_GROUND, ON_SAND, LOST
    float       mass;           //In KG
    float       speed;          //In m/s
    float       direction;      //Angle of the vector
} BALL;

void ball_update(BALL *ball);

void ball_paint(BALL *ball);


#endif // BALL_H_INCLUDED

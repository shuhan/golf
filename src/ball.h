#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "common.h"

typedef struct {
    GAMECIRCLE  shape;  //Shape of the ball
    float       mass;   //In KG
    int         lost;   //If lost, don't draw
} BALL;


#endif // BALL_H_INCLUDED

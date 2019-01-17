#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "animation.h"
#include "meters.h"

typedef struct {

    ANIMATIONCLIP   animation;
    METER           angle_meter;
    METER           force_meter;
    int             current_level;
    int             current_hit_count;
    int             total_score;

} PLAYER;

#endif // PLAYER_H_INCLUDED

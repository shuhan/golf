#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <graphics_lib.h>
#include "animation.h"
#include "meters.h"

#define PLAYER_PLAYING          0
#define PLAYER_WON              1

typedef struct {
    ANIMATIONCLIP   animation;
    char            winframe_path[300];
    unsigned        state;
    int             current_hit_count;
    BITMAP          winframe;

} PLAYER;

void player_init(PLAYER *player);

void player_destroy(PLAYER *player);

void player_paint(PLAYER *player);

#endif // PLAYER_H_INCLUDED

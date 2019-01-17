#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "common.h"
#include "ball.h"
#include "button.h"
#include "cloud.h"
#include "weather.h"
#include "animation.h"
#include "ground.h"
#include "meters.h"
#include "tree.h"
#include "lake.h"
#include "dune.h"
#include "hill.h"
#include "hole.h"
#include "player.h"

typedef struct {

    PLAYER      player;
    GROUND      ground;
    BALL        ball;
    HOLE        hole;
    TREE        *trees;
    int         tree_count;
    LAKE        *lakes;
    int         lake_count;
    DUNE        *dunes;
    int         dune_count;
    HILL        *hills;
    int         hill_count;
    CLOUD       *clouds;
    int         cloud_count;

} GAMELEVEL;

void gamelevel_paint(GAMELEVEL *level);

#endif // LEVEL_H_INCLUDED

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

#define GAMESTATE_SELECT_ANGLE      0       //Default state, select angle
#define GAMESTATE_SELECT_SPEED      1       //Then select speed
#define GAMESTATE_BALL_HIT          2       //Ball was hit
#define GAMESTATE_BALL_STOPPED      3       //Ball Stopped -> Now either win or go back to default state
#define GAMESTATE_WIN               4       //Game win, Go to next level

typedef struct {

    PLAYER      player;
    GROUND      ground;
    BALL        ball;
    HOLE        hole;
    METER       angle_meter;
    METER       speed_meter;
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
    int         max_points;
    unsigned    game_state;

} GAMELEVEL;

void gamelevel_reset(GAMELEVEL *level);

void gamelevel_update(GAMELEVEL *level);

void gamelevel_paint(GAMELEVEL *level);

#endif // LEVEL_H_INCLUDED

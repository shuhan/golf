#ifndef LEADERBOARD_H_INCLUDED
#define LEADERBOARD_H_INCLUDED

#include "common.h"
#include "ground.h"

typedef struct {
    GROUND ground;
    //Use an additional score as a temporary score
    //To decide if the new score shall be included in the list
    GAMESCORE scores[MAX_SCORES + 1];
    int count;
} LEADERBOARD;

void leaderboard_read(LEADERBOARD *leaderboard, const char *file);

void leaderboard_write(LEADERBOARD *leaderboard, const char *file);

void leaderboard_add_score(LEADERBOARD *leaderboard, GAMESCORE score);

void leaderboard_update(LEADERBOARD *leaderboard);

void leaderboard_paint(LEADERBOARD leaderboard);

#endif // LEADERBOARD_H_INCLUDED

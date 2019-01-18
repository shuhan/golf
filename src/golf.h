#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "button.h"
#include "level.h"

#define GAME_WELCOME        0
#define GAME_PLAY           1
#define GAME_PAUSE          2
#define GAME_END            3
#define GAME_LEADERBOARD    4

typedef struct {

    GAMEMENU        welcome_screen;
    GAMEMENU        pause_screen;
    GAMELEVEL       levels[9];
    int             current_level;
    unsigned        game_state;

    /**
     * Require additional two screens
     * 1. Leader board
     * 2. End Screen
     */

} GOLF;

void golf_init(GOLF *golf);

void golf_update(GOLF *golf);

void golf_paint(GOLF *golf);

//==============================================================================
//  Internal functions required for processing inputs and events
//==============================================================================

#endif // GAME_H_INCLUDED

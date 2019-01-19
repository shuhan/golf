#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "button.h"
#include "level.h"
#include "common.h"

#define GAME_WELCOME        0
#define GAME_PLAY           1
#define GAME_PAUSE          2
#define GAME_END            3
#define GAME_LEADERBOARD    4

typedef struct {

    GAMEMENU        welcome_screen;
    GAMEMENU        pause_screen;
    PLAYER          player;
    GAMELEVEL       levels[NUMBER_OF_LEVELS];
    int             current_level;
    int             total_score;
    unsigned        game_state;
    GAMEWEATHER     current_weather;
    int             gametorun;
    /**
     * Require additional two screens
     * 1. Leader board
     * 2. End Screen
     */

} GOLF;

//-------------------------------------------------
//  An instance of golf, required for global events
//-------------------------------------------------
GOLF *golf_game;

void golf_init(GOLF *golf);

int golf_update(GOLF *golf);

void golf_paint(GOLF *golf);

void golf_destroy(GOLF *golf);

//-----------------------------------------------------
//  Internal functions for processing inputs and events
//-----------------------------------------------------
void welcome_button_clicked(GAMEBUTTON button);

void pause_button_clicked(GAMEBUTTON button);

#endif // GAME_H_INCLUDED

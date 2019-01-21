#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "button.h"
#include "level.h"
#include "common.h"
#include "endscreen.h"
#include "leaderboard.h"
#include "soundplayer.h"

#define GAME_WELCOME        0
#define GAME_PLAY           1
#define GAME_PAUSE          2
#define GAME_END            3
#define GAME_LEADERBOARD    4

typedef struct {

    GAMEMENU        welcome_screen;
    GAMEMENU        pause_screen;
    ENDSCREEN       end_screen;
    LEADERBOARD     leaderboard;
    SOUNDPLAYER     sound_player;
    PLAYER          player;
    GAMELEVEL       levels[NUMBER_OF_LEVELS];
    int             current_level;
    int             total_score;
    unsigned        game_state;
    GAMEWEATHER     current_weather;
    int             gametorun;

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

void play_on_hit();

void play_on_ball_stop(BALL ball);

void play_on_level_complete();

void end_on_completed(ENDSCREEN screen);

#endif // GAME_H_INCLUDED

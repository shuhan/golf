#include "level.h"

void gamelevel_reset(GAMELEVEL *level) {
    //Reset Ball
    level->ball.state = BALL_STATIC;
    level->ball.horizontal_speed = 0;
    level->ball.vertical_speed = 0;
    level->ball.shape.centre.x = BALL_X;
    level->ball.shape.centre.y = BALL_Y;
    //Reset Player
    level->player.animation.left = level->ball.shape.centre.x - PLAYER_X_OFFSET;
    level->player.animation.top = level->ball.shape.centre.y - PLAYER_Y_OFFSET;
    animation_reset(level->player->animation);
    level->player.state = PLAYER_PLAYING;
    level->player.current_hit_count = 0;
    //Reset State
    level->game_state = GAMESTATE_SELECT_ANGLE;
}

void gamelevel_update(GAMELEVEL *level) {

    switch(level->game_state) {
        case GAMESTATE_SELECT_ANGLE:

        break;
        case GAMESTATE_SELECT_SPEED:

        break;
        case GAMESTATE_BALL_HIT:

        break;
        case GAMESTATE_BALL_STOPPED:

        break;
        case GAMESTATE_WIN:

        break;
    }

}

void gamelevel_paint(GAMELEVEL *level) {

    switch(level->game_state) {
        case GAMESTATE_SELECT_ANGLE:

        break;
        case GAMESTATE_SELECT_SPEED:

        break;
        case GAMESTATE_BALL_HIT:

        break;
        case GAMESTATE_BALL_STOPPED:

        break;
        case GAMESTATE_WIN:

        break;
    }

}


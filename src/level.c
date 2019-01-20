#include "level.h"

void gamelevel_reset(GAMELEVEL *level) {
    //Reset Ball
    level->ball.state = BALL_STATIC;
    level->ball.horizontal_speed = 0;
    level->ball.vertical_speed = 0;
    level->ball.shape.centre.x = BALL_X;
    level->ball.shape.centre.y = BALL_Y;
    //Reset Meters
    level->angle_meter.left = level->ball.shape.centre.x;
    level->angle_meter.top  = level->ball.shape.centre.y;
    level->speed_meter.left = level->ball.shape.centre.x + SPEED_METER_OFFSET;
    level->speed_meter.top  = level->ball.shape.centre.y;
    //Reset Player
    level->player.animation.left = level->ball.shape.centre.x - PLAYER_X_OFFSET;
    level->player.animation.top = level->ball.shape.centre.y - PLAYER_Y_OFFSET;
    animation_reset(&level->player.animation);
    level->player.state = PLAYER_PLAYING;
    level->player.current_hit_count = 0;
    //Reset State
    level->game_state = GAMESTATE_SELECT_ANGLE;
}

void gamelevel_update(GAMELEVEL *level, GAMEWEATHER weather) {

    int i;

    for(i = 0; i < level->cloud_count; i++) cloud_influence(&level->clouds[i], weather, WIND_INFLUENCE_ON_CLOUD);

    //Both meters shall be marked as not selecting and turn on selecting only if the game state requires
    level->angle_meter.selecting = 0;
    level->speed_meter.selecting = 0;

    switch(level->game_state) {
        case GAMESTATE_SELECT_ANGLE:
            level->angle_meter.selecting = 1;
            meter_update(&level->angle_meter);
            if(gamelevel_mouse_left_click(level)) {
                level->angle_meter.selecting = 0;
                level->game_state = GAMESTATE_SELECT_SPEED;
            }
        break;
        case GAMESTATE_SELECT_SPEED:
            level->speed_meter.selecting = 1;
            meter_update(&level->speed_meter);
            if(gamelevel_mouse_left_click(level)) {
                level->speed_meter.selecting = 0;
                level->player.animation.play = 1;
                level->game_state = GAMESTATE_BALL_HIT;
            } else if(gamelevel_mouse_right_click(level)){
                //Right click to go back to angle selection
                level->game_state = GAMESTATE_SELECT_ANGLE;
            }
        break;
        case GAMESTATE_BALL_HIT:
            animation_update(&level->player.animation);

            if(ball_update(&level->ball, weather, WIND_INFLUENCE_ON_BALL)) {
                ground_hit(level->ground, &level->ball);
                for(i = 0; i < level->tree_count; i++) tree_hit(level->trees[i], &level->ball);
                for(i = 0; i < level->lake_count; i++) lake_hit(level->lakes[i], &level->ball);
                for(i = 0; i < level->dune_count; i++) dune_hit(level->dunes[i], &level->ball);
                for(i = 0; i < level->hill_count; i++) hill_hit(level->hills[i], &level->ball);
                hole_hit(level->hole, &level->ball);
            }
        break;
        case GAMESTATE_WIN:
            level->player.state = PLAYER_WON;
            if(gamelevel_mouse_left_click(level)) {
                if(level->on_complete) level->on_complete();
            }
        break;
    }
}

void gamelevel_paint(GAMELEVEL *level) {

    setbkcolor(LIGHTBLUE);

    ground_paint(&(level->ground));

    int i;

    for(i = 0; i < level->cloud_count; i++) {
        cloud_paint(level->clouds[i]);
    }

    for(i = 0; i < level->dune_count; i++) {
        dune_paint(level->dunes + i);
    }

    for(i = 0; i < level->lake_count; i++) {
        lake_paint(level->lakes + i);
    }

    for(i = 0; i < level->hill_count; i++) {
        hill_paint(level->hills + i);
    }

    for(i = 0; i < level->tree_count; i++) {
        tree_paint(level->trees + i);
    }

    hole_paint(&level->hole);

    player_paint(&level->player);

    ball_paint(&level->ball);

    switch(level->game_state) {
        case GAMESTATE_SELECT_ANGLE:
            meter_paint_angle(level->angle_meter);
        break;
        case GAMESTATE_SELECT_SPEED:
            meter_paint_strength(level->speed_meter);
        break;
        case GAMESTATE_BALL_HIT:

        break;
        case GAMESTATE_WIN:;

            char congrets[128]= "Congratulations! You Won! Please Click to Continue!";

            int line_height = get_line_height();
            int text_width  = get_text_width(congrets);

            setcolor(WIN_TEXT_COLOUR);

            outtextxy(((WIDTH - text_width) / 2), ((HEIGHT - line_height) / 3), congrets);

        break;
    }
}

void gamelevel_destroy(GAMELEVEL *level) {
    if(level->clouds)   free(level->clouds);
    if(level->trees)    free(level->trees);
    if(level->lakes)    free(level->lakes);
    if(level->dunes)    free(level->dunes);
    if(level->hills)    free(level->hills);

    player_destroy(&level->player);
}

int gamelevel_mouse_left_click(GAMELEVEL *level) {
    int retval = 0;

    if(event_mouse_left_button_down()) {
        level->mouse_state++;               //Event is fired on mouse down and up, there fore keep count to make sure a down and up is required for a click
        if(level->mouse_state >= 2) {
            retval = 1;
            level->mouse_state = 0;         //Reset mouse state once click is counted
        }
        event.mouse.button = 0;             //Nasty hack stop event from sticking
    }

    return retval;
}

int gamelevel_mouse_right_click(GAMELEVEL *level) {
    int retval = 0;

    if(event_mouse_right_button_down()) {
        level->mouse_state++;               //Event is fired on mouse down and up, there fore keep count to make sure a down and up is required for a click
        if(level->mouse_state >= 2) {
            retval = 1;
            level->mouse_state = 0;         //Reset mouse state once click is counted
        }
        event.mouse.button = 0;             //Nasty hack stop event from sticking
    }

    return retval;
}

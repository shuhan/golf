#include "level_factory.h"

/**
 * Create the levels and return the pointer
 *------------------------------------------------------------------
 * 1. Plain area without any obstacles, one tree after the hole.
 * 2. Single dune before hole
 * 3. Single lake before hole
 * 4. Single hill before hole and a tree after hole
 * 5. Single tree before hole
 * 6. Single tree and a dune before hole
 * 7. Hill before a tree
 * 8. Lake after a tree
 * 9. Tree close to ball hill close to hole
 *******************************************************************/
void create_game_levels(GAMELEVEL levels[NUMBER_OF_LEVELS]) {

    int i;

    for(i = 0; i < NUMBER_OF_LEVELS; i++) {

        ANIMATIONFRAME frames[4] = {
            {GRAPHICS_FRAME_PATH_0, 0, 0, 0},
            {GRAPHICS_FRAME_PATH_1, 0, 0, 0},
            {GRAPHICS_FRAME_PATH_2, 0, 0, 1},
            {GRAPHICS_FRAME_PATH_3, 0, 0, 0}
        };
        strcpy(levels[i].player.winframe_path, GRAPHICS_FRAME_PATH_WIN);
        levels[i].player.animation.current_frame    = 0;
        levels[i].player.animation.frames[0]        = frames[0];
        levels[i].player.animation.frames[1]        = frames[1];
        levels[i].player.animation.frames[2]        = frames[2];
        levels[i].player.animation.frames[3]        = frames[3];
        levels[i].player.animation.frame_count      = 4;
        levels[i].player.animation.frame_progress   = 0;
        levels[i].player.animation.incriment_rate   = FRAME_PROGRESS_RATE;
        levels[i].player.animation.play             = 0;
        levels[i].player.animation.loop             = 0;
        levels[i].player.animation.left             = BALL_X - PLAYER_X_OFFSET;
        levels[i].player.animation.top              = BALL_Y - PLAYER_Y_OFFSET;
        levels[i].player.current_hit_count          = 0;
        levels[i].player.state                      = PLAYER_PLAYING;
        //Player.animation.on_activation event needs to be set later

        GROUND ground = { WIDTH, HEIGHT, GROUND_TOP_LINE, GROUND_LINE };
        levels[i].ground = ground;

        BALL ball = {{{BALL_X, BALL_Y}, BALL_RADIUS}, BALL_STATIC};
        levels[i].ball = ball;
        //Ball stopped event needs to be set later

        //Hole
        HOLE hole = {HOLE_X, HOLE_Y, HOLE_WIDTH_STANDARD, HOLE_HEIGHT_STANDARD};
        levels[i].hole = hole;

        //Angle Meter
        METER angle_meter = {
            BALL_X,
            BALL_Y,
            ANGLE_METER_SIZE,
            ANGLE_METER_MIN,
            ANGLE_METER_MAX,
            METER_BACK_COLOUR,
            METER_FORE_COLOUR,
            METER_SPEED_FACTOR,
            ANGLE_METER_WIDTH
        };
        levels[i].angle_meter = angle_meter;
        //Speed Meter
        METER speed_meter = {
            BALL_X + SPEED_METER_OFFSET,
            BALL_Y,
            SPEED_METER_SIZE,
            SPEED_METER_MIN,
            SPEED_METER_MAX,
            METER_BACK_COLOUR,
            METER_FORE_COLOUR,
            METER_SPEED_FACTOR,
            SPEED_METER_WIDTH
        };
        levels[i].speed_meter = speed_meter;

        levels[i].max_points = 100 * (i + 1);
        levels[i].game_state = GAMESTATE_SELECT_ANGLE;

        //Reset count for all other objects and then set them separately


        switch(i) {
            case 0:

            break;
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
            case 7:

            break;
            case 8:

            break;
        }
    }
}

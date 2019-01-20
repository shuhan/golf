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
void create_game_levels(GAMELEVEL levels[NUMBER_OF_LEVELS], void (*on_activation)(void), void (*on_stop)(BALL), void (*on_complete)(void)) {

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
        levels[i].player.animation.on_activation    = on_activation;

        GROUND ground = { WIDTH, HEIGHT, GROUND_TOP_LINE, GROUND_LINE };
        levels[i].ground = ground;

        BALL ball = {{{BALL_X, BALL_Y}, BALL_RADIUS}, BALL_STATIC};
        levels[i].ball = ball;
        levels[i].ball.on_stop = on_stop;

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
        meter_init(&levels[i].angle_meter);
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
        meter_init(&levels[i].speed_meter);

        levels[i].max_points = 100 * (i + 1);
        levels[i].game_state = GAMESTATE_SELECT_ANGLE;
        levels[i].mouse_state= 0;
        levels[i].on_complete= on_complete;

        //Reset count for all other objects and then set them separately
        levels[i].trees         = 0;
        levels[i].tree_count    = 0;
        levels[i].lakes         = 0;
        levels[i].lake_count    = 0;
        levels[i].dunes         = 0;
        levels[i].dune_count    = 0;
        levels[i].hills         = 0;
        levels[i].hill_count    = 0;

        CLOUD clouds[1] = {
            { random_number(0, WIDTH), random_number(CLOUD_POSITION_Y - CLOUD_SIZE_STANDARD, CLOUD_POSITION_Y + CLOUD_SIZE_STANDARD), CLOUD_SIZE_STANDARD, CLOUD_SHAPE_FACTOR }
        };
        alocncpy((void**)&levels[i].clouds, (void*)clouds, sizeof(clouds));
        levels[i].cloud_count = 1;

        switch(i) {
            case 0: ; //C don't allow declaration immediately after a level
                TREE trees1[1] = {{ LEVEL_1_TREE_X, GROUND_LINE, TREE_SIZE_STANDARD }};
                alocncpy((void**)&levels[i].trees, (void*)trees1, sizeof(trees1));
                levels[i].tree_count = 1;
            break;
            case 1: ; //C don't allow declaration immediately after a level
                DUNE dunes2[1] = {{ LEVEL_2_DUNE_X, GROUND_LINE, DUNE_WIDTH_STANDARD, DUNE_HEIGHT_STANDARD }};
                alocncpy((void**)&levels[i].dunes, (void*)dunes2, sizeof(dunes2));
                levels[i].dune_count = 1;
            break;
            case 2: ; //C don't allow declaration immediately after a level
                LAKE lakes3[1] = {{ LEVEL_3_LAKE_X, GROUND_LINE, LAKE_WIDTH_STANDARD, LAKE_HEIGHT_STANDARD }};
                alocncpy((void**)&levels[i].lakes, (void*)lakes3, sizeof(lakes3));
                levels[i].lake_count = 1;
            break;
            case 3: ; //C don't allow declaration immediately after a level
                TREE trees4[1] = {{ LEVEL_4_TREE_X, GROUND_LINE, TREE_SIZE_STANDARD }};
                alocncpy((void**)&levels[i].trees, (void*)trees4, sizeof(trees4));
                levels[i].tree_count = 1;

                HILL hills4[1] = {{ LEVEL_4_HILL_X, GROUND_LINE, HILL_RADIUS_STANDARD, HILL_HEIGHT_STANDARD, HILL_PEAK_DISTANCE }};
                alocncpy((void**)&levels[i].hills, (void*)hills4, sizeof(hills4));
                levels[i].hill_count = 1;
            break;
            case 4: ; //C don't allow declaration immediately after a level
                TREE trees5[1] = {{ LEVEL_5_TREE_X, GROUND_LINE, TREE_SIZE_SMALL }};
                alocncpy((void**)&levels[i].trees, (void*)trees5, sizeof(trees5));
                levels[i].tree_count = 1;
            break;
            case 5: ; //C don't allow declaration immediately after a level
                TREE trees6[1] = {{ LEVEL_6_TREE_X, GROUND_LINE, TREE_SIZE_STANDARD }};
                alocncpy((void**)&levels[i].trees, (void*)trees6, sizeof(trees6));
                levels[i].tree_count = 1;

                DUNE dunes6[1] = {{ LEVEL_6_DUNE_X, GROUND_LINE, DUNE_WIDTH_STANDARD, DUNE_HEIGHT_STANDARD }};
                alocncpy((void**)&levels[i].dunes, (void*)dunes6, sizeof(dunes6));
                levels[i].dune_count = 1;
            break;
            case 6: ; //C don't allow declaration immediately after a level
                TREE trees7[1] = {{ LEVEL_7_TREE_X, GROUND_LINE, TREE_SIZE_SMALL }};
                alocncpy((void**)&levels[i].trees, (void*)trees7, sizeof(trees7));
                levels[i].tree_count = 1;

                HILL hills7[1] = {{ LEVEL_7_HILL_X, GROUND_LINE, HILL_RADIUS_STANDARD, HILL_HEIGHT_STANDARD, HILL_PEAK_DISTANCE }};
                alocncpy((void**)&levels[i].hills, (void*)hills7, sizeof(hills7));
                levels[i].hill_count = 1;
            break;
            case 7: ; //C don't allow declaration immediately after a level
                TREE trees8[1] = {{ LEVEL_8_TREE_X, GROUND_LINE, TREE_SIZE_SMALL }};
                alocncpy((void**)&levels[i].trees, (void*)trees8, sizeof(trees8));
                levels[i].tree_count = 1;

                DUNE dunes8[1] = {{ LEVEL_8_DUNE_X, GROUND_LINE, DUNE_WIDTH_STANDARD, DUNE_HEIGHT_STANDARD }};
                alocncpy((void**)&levels[i].dunes, (void*)dunes8, sizeof(dunes8));
                levels[i].dune_count = 1;
            break;
            case 8: ; //C don't allow declaration immediately after a level
                TREE trees9[1] = {{ LEVEL_9_TREE_X, GROUND_LINE, TREE_SIZE_SMALL }};
                alocncpy((void**)&levels[i].trees, (void*)trees9, sizeof(trees9));
                levels[i].tree_count = 1;

                DUNE dunes9[1] = {{ LEVEL_9_DUNE_X, GROUND_LINE, DUNE_WIDTH_SMALL, DUNE_HEIGHT_SMALL }};
                alocncpy((void**)&levels[i].dunes, (void*)dunes9, sizeof(dunes9));
                levels[i].dune_count = 1;

                HILL hills9[1] = {{ LEVEL_9_HILL_X, GROUND_LINE, HILL_RADIUS_SMALL, HILL_HEIGHT_SMALL, HILL_PEAK_DISTANCE }};
                alocncpy((void**)&levels[i].hills, (void*)hills9, sizeof(hills9));
                levels[i].hill_count = 1;
            break;
        }

        player_init(&levels[i].player);
    }
}

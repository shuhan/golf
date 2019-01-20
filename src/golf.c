#include "golf.h"
#include <graphics_lib.h>
#include <amio_lib.h>
#include "level_factory.h"

void golf_init(GOLF *golf) {

    //-------------------------------------------------
    //  Basic Initialization
    //-------------------------------------------------
    initwindow(WIDTH, HEIGHT);
    initfont();
    initkeyboard();
    initmouse();
    create_event_queue();
    reg_keyboard_events();
    reg_mouse_events();

    srand(time(0));

    gameweather_init();
    cloud_init(WIDTH);

    cleardevice();

    golf->gametorun = 1;

    //Copy the instance pointer to refer as current instance
    //As only one object of type golf is created at a time
    golf_game = golf;

    //-------------------------------------------------
    //  Game Parameters
    //-------------------------------------------------
    golf->current_level = 0;
    golf->total_score   = 0;
    golf->game_state    = GAME_WELCOME;
    //-------------------------------------------------
    //ToDo: Load saved game if any
    //-------------------------------------------------
    char has_savedata = 0;

    int total_score, current_level;

    FILE *file_handle = fopen(SAVE_FILE_PATH, "r");
    if(fscanf(file_handle, "%d,%d", &total_score, &current_level) == 2) {
        has_savedata = 1;
        golf->total_score   = total_score;
        golf->current_level = current_level;
    }
    fclose(file_handle);

    //-------------------------------------------------
    //1. Welcome Screen
    //-------------------------------------------------
    int welcome_top = (HEIGHT - ((BUTTON_HEIGHT + BUTTON_MARGIN) * (WELCOME_BUTTON_COUNT))) / 2;

    GAMEBUTTON welcome_buttons[WELCOME_BUTTON_COUNT] = {
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (0 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "CONTINUE",                                                 //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            welcome_button_clicked,                                     //Handle welcome screen button click
            0,                                                          //Initially don't highlight
            has_savedata,                                               //Continue button shall be visible only if there is saved data
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (1 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "NEW GAME",                                                 //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            welcome_button_clicked,                                     //Handle welcome screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (2 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "LEADER BOARD",                                             //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            welcome_button_clicked,                                     //Handle welcome screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (3 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "EXIT",                                                     //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            welcome_button_clicked,                                     //Handle welcome screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        }
    };

    alocncpy((void**)&(golf->welcome_screen.buttons), (void*)welcome_buttons, sizeof(welcome_buttons));
    golf->welcome_screen.button_count   = WELCOME_BUTTON_COUNT;

    //Add the ground
    GROUND ground = {WIDTH, HEIGHT, GROUND_TOP_LINE, GROUND_LINE };
    golf->welcome_screen.ground = ground;

    //Add Cloud
    CLOUD clouds[1] = {{ random_number(0, WIDTH), random_number(CLOUD_POSITION_Y - CLOUD_SIZE_STANDARD, CLOUD_POSITION_Y + CLOUD_SIZE_STANDARD), CLOUD_SIZE_STANDARD, CLOUD_SHAPE_FACTOR }};
    alocncpy((void**)&golf->welcome_screen.clouds, (void*)clouds, sizeof(clouds));
    golf->welcome_screen.cloud_count = 1;

    //Add Tree
    TREE trees[1] = {{ (WIDTH * 3)/4, GROUND_LINE, TREE_SIZE_STANDARD }};
    alocncpy((void**)&golf->welcome_screen.trees, (void*)trees, sizeof(trees));
    golf->welcome_screen.tree_count = 1;

    //Add Lake
    LAKE lakes[1] = {{ ((WIDTH * 3)/4) - (LAKE_WIDTH_STANDARD + WELCOME_LAKE_OFFSET), GROUND_LINE, LAKE_WIDTH_STANDARD, LAKE_HEIGHT_STANDARD }};
    alocncpy((void**)&golf->welcome_screen.lakes, (void*)lakes, sizeof(lakes));
    golf->welcome_screen.lake_count = 1;

    //No Dunes
    golf->welcome_screen.dunes = 0;
    golf->welcome_screen.dune_count = 0;


    //-------------------------------------------------
    //2. Pause Screen
    //-------------------------------------------------

    int pause_top = (HEIGHT - ((BUTTON_HEIGHT + BUTTON_MARGIN) * (PAUSE_BUTTON_COUNT))) / 2;

    GAMEBUTTON pause_buttons[PAUSE_BUTTON_COUNT] = {
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            pause_top + (0 * (BUTTON_HEIGHT + BUTTON_MARGIN)),          //Top
            "RESUME",                                                   //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            pause_button_clicked,                                       //Handle pause screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            pause_top + (1 * (BUTTON_HEIGHT + BUTTON_MARGIN)),          //Top
            "RE-START LEVEL",                                           //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            pause_button_clicked,                                       //Handle pause screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            pause_top + (2 * (BUTTON_HEIGHT + BUTTON_MARGIN)),          //Top
            "EXIT LEVEL",                                               //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            pause_button_clicked,                                       //Handle pause screen button click
            0,                                                          //Initially don't highlight
            1,                                                          //Always visible
            0                                                           //Mouse state 0 indicating mouse isn't pressed
        }
    };

    alocncpy((void**)&golf->pause_screen.buttons, (void*)pause_buttons, sizeof(pause_buttons));
    golf->pause_screen.button_count = PAUSE_BUTTON_COUNT;

    //Add the ground (Reuse from previous definition)
    golf->pause_screen.ground = ground;

    //Add Cloud (Reuse from previous definition)
    alocncpy((void**)&golf->pause_screen.clouds, (void*)clouds, sizeof(clouds));
    golf->pause_screen.cloud_count = 1;

    //Add Tree (Reuse from previous definition)
    alocncpy((void**)&golf->pause_screen.trees, (void*)trees, sizeof(trees));
    golf->pause_screen.tree_count = 1;

    //Add Dune
    DUNE dunes[1] = {{ ((WIDTH * 3)/4) - (DUNE_WIDTH_STANDARD + PAUSE_DUNE_OFFSET), GROUND_LINE, DUNE_WIDTH_STANDARD, DUNE_HEIGHT_STANDARD }};
    alocncpy((void**)&golf->pause_screen.dunes, (void*)dunes, sizeof(dunes));
    golf->pause_screen.dune_count = 1;

    //No Lakes
    golf->pause_screen.lakes = 0;
    golf->pause_screen.lake_count = 0;

    //-------------------------------------------------
    //3. Create Game Screens
    //-------------------------------------------------
    create_game_levels(golf->levels, play_on_hit, play_on_ball_stop, play_on_level_complete);

    /**
     * Additional Pending Game Screens
     * ------------------------------------------------
     * 1. Leader board
     * 2. End Screen
     */
}

int golf_update(GOLF *golf) {
    //Wait for mouse event
    //Use allegro function directly as there is no reliable function in the wrapper
    al_wait_for_event_timed(event_queue, &event, 0.00);

    golf->current_weather = gameweather_now();

    switch(golf->game_state) {
        case GAME_WELCOME:
            gamemenu_check_mouse(golf->welcome_screen);
        break;
        case GAME_PLAY:
            gamelevel_update(&golf->levels[golf->current_level], golf->current_weather);
            if(event_key('p')) {
                golf->game_state = GAME_PAUSE;
            }
        break;
        case GAME_PAUSE:
            gamemenu_check_mouse(golf->pause_screen);
        break;
        case GAME_END:

        break;
        case GAME_LEADERBOARD:
            if(event_mouse_right_button_down()) {
                golf->game_state = GAME_WELCOME;
            }
        break;
    }

    return golf->gametorun;
}

void golf_paint(GOLF *golf) {

    cleardevice();

    switch(golf->game_state) {
        case GAME_WELCOME:
            gamemenu_paint(golf->welcome_screen, golf->current_weather);
        break;
        case GAME_PLAY:
            gamelevel_paint(&golf->levels[golf->current_level]);

            char level_name[64], score_text[64], hit_count_text[64];
            sprintf(level_name, "Level %d", golf->current_level + 1);
            sprintf(score_text, "Total Score  %d", golf->total_score);
            sprintf(hit_count_text, "Hit Count    %d", golf_game->levels[golf_game->current_level].player.current_hit_count);

            int line_height = get_line_height();

            setcolor(SCORE_TEXT_COLOUR);

            outtextxy(SCORE_TEXT_OFFSET, SCORE_TEXT_OFFSET, level_name);
            outtextxy(SCORE_TEXT_OFFSET, line_height + (2*SCORE_TEXT_OFFSET), score_text);
            outtextxy(SCORE_TEXT_OFFSET, (2*line_height) + (3*SCORE_TEXT_OFFSET), hit_count_text);

            setcolor(SCORE_TEXT_SHADOW);

            outtextxy(SCORE_TEXT_OFFSET + 1, SCORE_TEXT_OFFSET + 1, level_name);
            outtextxy(SCORE_TEXT_OFFSET + 1, line_height + (2*SCORE_TEXT_OFFSET) + 1, score_text);
            outtextxy(SCORE_TEXT_OFFSET + 1, (2*line_height) + (3*SCORE_TEXT_OFFSET) + 1, hit_count_text);

        break;
        case GAME_PAUSE:
            gamemenu_paint(golf->pause_screen, golf->current_weather);
        break;
        case GAME_END:

        break;
        case GAME_LEADERBOARD:

        break;
    }

    update_display();
}

void golf_destroy(GOLF *golf) {
    int i;
    //-------------------------------------------------
    //  Close Keyboard, Mouse and Graphics Window
    //-------------------------------------------------
    closekeyboard();
    closemouse();
    closegraph();
    //-------------------------------------------------
    //  Release all Game Menu
    //-------------------------------------------------
    gamemenu_destroy(&golf->welcome_screen);
    gamemenu_destroy(&golf->pause_screen);
    //-------------------------------------------------
    //  Release all Levels
    //-------------------------------------------------
    for(i = 0; i < NUMBER_OF_LEVELS; i++)
        gamelevel_destroy(&golf->levels[i]);
}

/**
 *  Handle Welcome Screen Button Click
 ******************************************************/
void welcome_button_clicked(GAMEBUTTON button) {
    if(strcmp(button.text, "CONTINUE") == 0) {
        gamelevel_reset(&golf_game->levels[golf_game->current_level]);
        golf_game->game_state = GAME_PLAY;
    }
    if(strcmp(button.text, "NEW GAME") == 0) {
        golf_game->current_level = 0;
        gamelevel_reset(&golf_game->levels[golf_game->current_level]);
        golf_game->game_state = GAME_PLAY;
    }
    if(strcmp(button.text, "LEADER BOARD") == 0) {
        golf_game->game_state = GAME_LEADERBOARD;
    }
    if(strcmp(button.text, "EXIT") == 0) {
        golf_game->gametorun = 0;
    }
}

/**
 *  Handle Pause Screen Button Click
 ******************************************************/
 void pause_button_clicked(GAMEBUTTON button) {
    if(strcmp(button.text, "RESUME") == 0) {
        golf_game->game_state = GAME_PLAY;
    }
    if(strcmp(button.text, "RE-START LEVEL") == 0) {
        gamelevel_reset(&golf_game->levels[golf_game->current_level]);
        golf_game->game_state = GAME_PLAY;
    }
    if(strcmp(button.text, "EXIT LEVEL") == 0) {
        golf_game->game_state = GAME_WELCOME;
    }
 }

 /**
 *  Handle Play Screen Ball Hit Event
 ******************************************************/
void play_on_hit() {
    ball_hit(&golf_game->levels[golf_game->current_level].ball,
             golf_game->levels[golf_game->current_level].speed_meter.current_reading,
             golf_game->levels[golf_game->current_level].angle_meter.current_reading);
}

 /**
 *  Handle Play Screen Ball Stop Event
 ******************************************************/
void play_on_ball_stop(BALL ball) {
    switch(ball.state) {
        case BALL_ON_GROUND:
        case BALL_ON_SAND:
            golf_game->levels[golf_game->current_level].player.current_hit_count++;
            //Update player
            golf_game->levels[golf_game->current_level].player.animation.left = golf_game->levels[golf_game->current_level].ball.shape.centre.x - PLAYER_X_OFFSET;
            golf_game->levels[golf_game->current_level].player.animation.top = golf_game->levels[golf_game->current_level].ball.shape.centre.y - PLAYER_Y_OFFSET;
            animation_reset(&golf_game->levels[golf_game->current_level].player.animation);
            golf_game->levels[golf_game->current_level].player.state = PLAYER_PLAYING;

            //Meters
            golf_game->levels[golf_game->current_level].angle_meter.left = golf_game->levels[golf_game->current_level].ball.shape.centre.x;
            golf_game->levels[golf_game->current_level].speed_meter.left = golf_game->levels[golf_game->current_level].ball.shape.centre.x + SPEED_METER_OFFSET;

            golf_game->levels[golf_game->current_level].game_state = GAMESTATE_SELECT_ANGLE;
        break;
        case BALL_IN_HOLE:
            golf_game->total_score += (golf_game->levels[golf_game->current_level].max_points - (golf_game->levels[golf_game->current_level].player.current_hit_count * HIT_LOSS_CONSTANT));
            golf_game->levels[golf_game->current_level].game_state = GAMESTATE_WIN;
        break;
        case BALL_LOST:;
            int hitcount = golf_game->levels[golf_game->current_level].player.current_hit_count;
            gamelevel_reset(&golf_game->levels[golf_game->current_level]);
            golf_game->levels[golf_game->current_level].player.current_hit_count = hitcount + 1;
        break;
    }
}

 /**
 *  Handle Play Screen Level Complete Event
 ******************************************************/
void play_on_level_complete() {
    if(golf_game->current_level < (NUMBER_OF_LEVELS - 1)) {
        golf_game->current_level++;
        gamelevel_reset(&golf_game->levels[golf_game->current_level]);
        golf_game->game_state = GAME_PLAY;

        //Save progress here
        //Total Score & Current Level
        FILE *file_handle = fopen(SAVE_FILE_PATH, "w");
        fprintf(file_handle, "%d,%d", golf_game->total_score, golf_game->current_level);
        fclose(file_handle);

    } else {
        golf_game->game_state = GAME_END;

        //Clear saved data so that only new game is available
        FILE *file_handle = fopen(SAVE_FILE_PATH, "w");
        fprintf(file_handle, "");
        fclose(file_handle);
    }
}

#include "golf.h"
#include <graphics_lib.h>
#include <amio_lib.h>

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
    golf->game_state    = GAME_WELCOME;
    //-------------------------------------------------
    //ToDo: Load saved game if any
    //-------------------------------------------------
    char has_savedata = 0;

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
    //-------------------------------------------------
    //  Close Keyboard, Mouse and Graphics Window
    //-------------------------------------------------
    closekeyboard();
    closemouse();
    closegraph();
    //-------------------------------------------------
    //  Release all pointers
    //-------------------------------------------------
    gamemenu_destroy(&golf->welcome_screen);
    gamemenu_destroy(&golf->pause_screen);
    //-------------------------------------------------
    //  Release all Image and Audio resources
    //-------------------------------------------------

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

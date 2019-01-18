#include "golf.h"

void golf_init(GOLF *golf) {

    //-------------------------------------------------
    //Basic Initialization
    //-------------------------------------------------
    initwindow(WIDTH, HEIGHT);
    initfont();
    initkeyboard();
    initmouse();
    create_event_queue();
    reg_keyboard_events();
    reg_mouse_events();

    gameweather_init();
    cloud_init(WIDTH);

    cleardevice();
    //-------------------------------------------------
    //ToDo: Load saved game if any
    //-------------------------------------------------
    char has_savedata = 0;

    //-------------------------------------------------
    //1. Welcome Screen
    //-------------------------------------------------
    int welcome_top = (HEIGHT - ((BUTTON_HEIGHT + BUTTON_MARGIN) * (WELCOME_BUTTON_COUNT - 1)));

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
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            has_savedata                                                //Continue button shall be visible only if there is saved data
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
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Continue button shall be visible only if there is saved data
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (2 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "LEADER BOARD",                                                 //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Continue button shall be visible only if there is saved data
        },
        {
            (WIDTH - BUTTON_WIDTH) / 2,                                 //Left
            welcome_top + (3 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "EXIT",                                                 //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Continue button shall be visible only if there is saved data
        }
    };

    golf->welcome_screen.buttons        = welcome_buttons;
    golf->welcome_screen.button_count   = WELCOME_BUTTON_COUNT;

    //Add the ground
    GROUND ground = {WIDTH, HEIGHT, GROUND_TOP_LINE, GROUND_LINE };
    golf->welcome_screen.ground = ground;

    //Add Cloud
    CLOUD clouds[1] = {{ random_number(0, WIDTH), random_number(CLOUD_POSITION_Y - CLOUD_SIZE_STANDARD, CLOUD_POSITION_Y + CLOUD_SIZE_STANDARD), CLOUD_SIZE_STANDARD, CLOUD_SHAPE_FACTOR }};
    golf->welcome_screen.clouds = clouds;
    golf->welcome_screen.cloud_count = 1;

    //Add Tree
    TREE trees[1] = {{ (WIDTH * 2)/3, GROUND_LINE, TREE_SIZE_STANDARD }};
    golf->welcome_screen.trees = trees;
    golf->welcome_screen.tree_count = 1;

    //Add Lake
    LAKE lakes[1] = {{ ((WIDTH * 2)/3) - (LAKE_WIDTH_STANDARD * 2), GROUND_LINE, LAKE_WIDTH_STANDARD, LAKE_HEIGHT_STANDARD }};
    golf->welcome_screen.lakes = lakes;
    golf->welcome_screen.lake_count = 1;

    //No Dunes
    golf.welcome_screen.dunes = 0;
    golf->welcome_screen.dune_count = 0;


    //-------------------------------------------------
    //2. Pause Screen
    //-------------------------------------------------

    int pause_top = (HEIGHT - ((BUTTON_HEIGHT + BUTTON_MARGIN) * (PAUSE_BUTTON_COUNT - 1)));

    GAMEBUTTON pause_buttons[PAUSE_BUTTON_COUNT] = {
        {
            (WIDTH - BUTTON_WIDTH) / 2,                               //Left
            pause_top + (0 * (BUTTON_HEIGHT + BUTTON_MARGIN)),        //Top
            "RESUME",                                                 //Text
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            BUTTON_BACKCOLOUR,
            BUTTON_FORECOLOUR,
            BUTTON_HBACKCOLOUR,
            BUTTON_HFORECOLOUR,
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Always visible
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
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Always visible
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
            0,                                                          //Shall be button event
            0,                                                          //Initially don't highlight
            1                                                           //Always visible
        }
    };

    golf->pause_screen.buttons      = pause_buttons;
    golf->pause_screen.button_count = PAUSE_BUTTON_COUNT;

    //Add the ground (Reuse from previous definition)
    golf->pause_screen.ground = ground;

    //Add Cloud (Reuse from previous definition)
    golf->pause_screen.clouds = clouds;
    golf->pause_screen.cloud_count = 1;

    //Add Tree (Reuse from previous definition)
    golf->pause_screen.trees = trees;
    golf->pause_screen.tree_count = 1;

    //Add Dune
    DUNE dunes[1] = {{ ((WIDTH * 2)/3) - (LAKE_WIDTH_STANDARD * 2), GROUND_LINE, LAKE_WIDTH_STANDARD, LAKE_HEIGHT_STANDARD }};
    golf->pause_screen.dunes = dunes;
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

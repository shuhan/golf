#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <graphics_lib.h>

//-----------------------------------------------
//  Screen Size
//-----------------------------------------------
#define WIDTH                   1200
#define HEIGHT                  675
//----------------------------------------------------------------------------------------
//  GAME ENVIRONMENT CONSTANTS
//  All environmental constants are optimized to provide better game-play based on tests
//----------------------------------------------------------------------------------------
#define GRAVITY_CONSTANT        4
#define AIR_LOSS                0.005
#define GROUND_LOSS             0.2
#define SAND_LOSS               0.5
#define HILL_LOSS               0.2
#define HILL_SHAKE              3
#define TREE_LOSS               0.3
#define TREE_LEAVES_SHAKE       5
#define MAX_HIT_SPEED           100
#define WIND_INFLUENCE_ON_BALL  0.05
#define WIND_INFLUENCE_ON_CLOUD 0.1
#define HILL_CONSUME_THREASHOLD 3                                       //If speed is less than this, ball will be lost in hill
//-----------------------------------------------
//  Additional Game Constants
//-----------------------------------------------
#define KEYBOARD_ESC_KEY        59
#define KEYBOARD_ENTER_KEY      67
#define KEYBOARD_BACKSPACE      63
#define MAX_NAME_LENGTH         128
#define MAX_SCORES              14
#define BALL_UPDATE_DELAY       9                                       //This is the ball position update interval in term of ticks
#define BASE_POINT_PER_LEVEL    100
#define HIT_LOSS_CONSTANT       2                                       //Score loss is quadratic
#define MINIMUM_POINT           0.1                                     //Someone pass the level will receive at least 10% even if in
//-----------------------------------------------
//  Buttons Configuration
//-----------------------------------------------
#define BUTTON_BACKCOLOUR       DARKDIRT
#define BUTTON_FORECOLOUR       WHITE
#define BUTTON_HBACKCOLOUR      DIRT
#define BUTTON_HFORECOLOUR      WHITE
#define BUTTON_WIDTH            250
#define BUTTON_HEIGHT           40
#define BUTTON_MARGIN           15
#define DEBOUNCING_DELAY        250
//-----------------------------------------------
//  Resource Constants
//-----------------------------------------------
#define GRAPHICS_FRAME_PATH_0   "data/res/0.png"
#define GRAPHICS_FRAME_PATH_1   "data/res/1.png"
#define GRAPHICS_FRAME_PATH_2   "data/res/2.png"
#define GRAPHICS_FRAME_PATH_3   "data/res/3.png"
#define GRAPHICS_FRAME_PATH_WIN "data/res/win.png"
#define BACKGROUND_SOUND_PATH   "data/res/drums.wav"
#define BALL_HIT_SOUND_PATH     "data/res/golf-club-swing.wav"
#define BALL_LOST_SOUND_PATH    "data/res/boo.wav"
#define LEVEL_WIN_SOUND_PATH    "data/res/applause.wav"
#define MAX_FRAME_COUNT         4                                   //Don't need more than 4 frames at the moment, only frame based animation is player which has 4 frames
#define FRAME_PROGRESS_RATE     0.05                                //Frame progress rate is defined based on test to create an smooth animation effect
#define SAVE_FILE_PATH          "save.golf"
#define LEADERBOARD_FILE_PATH   "leaderboard.golf"
//-----------------------------------------------
//  Object Size Standards
//-----------------------------------------------
#define CLOUD_POSITION_Y        HEIGHT/6
#define CLOUD_SIZE_STANDARD     50
#define CLOUD_SHAPE_FACTOR      1.5
#define TREE_SIZE_STANDARD      30
#define TREE_SIZE_SMALL         20
#define DUNE_WIDTH_STANDARD     150
#define DUNE_HEIGHT_STANDARD    75
#define DUNE_WIDTH_SMALL        90
#define DUNE_HEIGHT_SMALL       45
#define LAKE_WIDTH_STANDARD     150
#define LAKE_HEIGHT_STANDARD    75
#define HILL_RADIUS_SMALL       100
#define HILL_HEIGHT_SMALL       140
#define HILL_RADIUS_STANDARD    150
#define HILL_HEIGHT_STANDARD    210
#define HILL_PEAK_DISTANCE      0.3
#define HOLE_WIDTH_STANDARD     30
#define HOLE_HEIGHT_STANDARD    15
#define GROUND_TOP_LINE         (HEIGHT*2)/3
#define GROUND_LINE             (HEIGHT*5)/6
//-----------------------------------------------
//  Welcome Screen Constants
//-----------------------------------------------
#define WELCOME_BUTTON_COUNT    4
#define WELCOME_LAKE_OFFSET     LAKE_WIDTH_STANDARD*0.2
//-----------------------------------------------
//  Pause Screen Constants
//-----------------------------------------------
#define PAUSE_BUTTON_COUNT      3
#define PAUSE_DUNE_OFFSET       DUNE_WIDTH_STANDARD*0.2
//-----------------------------------------------
//  Play Screen Constants
//-----------------------------------------------
#define PLAYER_X_OFFSET         40
#define PLAYER_Y_OFFSET         55
#define HOLE_X                  (WIDTH*9)/10
#define HOLE_Y                  GROUND_LINE
#define BALL_X                  WIDTH/6
#define BALL_Y                  GROUND_LINE
#define BALL_RADIUS             10
#define METER_BACK_COLOUR       YELLOW
#define METER_FORE_COLOUR       BLACK
#define METER_SPEED_FACTOR      0.2
#define ANGLE_METER_SIZE        100
#define ANGLE_METER_WIDTH       20
#define ANGLE_METER_MAX         89
#define ANGLE_METER_MIN         0
#define SPEED_METER_SIZE        100
#define SPEED_METER_WIDTH       20
#define SPEED_METER_OFFSET      50
#define SPEED_METER_MAX         MAX_HIT_SPEED
#define SPEED_METER_MIN         0
#define NUMBER_OF_LEVELS        9
#define SCORE_TEXT_OFFSET       15
#define SCORE_TEXT_COLOUR       DARKDIRT
#define SCORE_TEXT_SHADOW       DIRT
#define WIN_TEXT_COLOUR         RED
//-----------------------------------------------
//  End Screen Constants
//-----------------------------------------------
#define TEXTBOX_WIDTH           250
#define TEXTBOX_HEIGHT          40
#define TEXTBOX_COLOUR          DARKDIRT
#define TEXTBOX_FORECOLOUR      WHITE
//-----------------------------------------------
//  Leaderboard Constants
//-----------------------------------------------
#define LEADERBOARD_COLOUR      DARKDIRT
#define LEADERBOARD_FORECOLOUR  WHITE
#define LEADERBOARD_WIDTH       (WIDTH/3)
#define LEADERBOARD_HEIGHT      ((HEIGHT*3)/4)
#define LEADERBOARD_TEXT_OFFSET 20
//-----------------------------------------------
//  Level 1 Constants
//-----------------------------------------------
#define LEVEL_1_TREE_X          (WIDTH*15)/16
//-----------------------------------------------
//  Level 2 Constants
//-----------------------------------------------
#define LEVEL_2_DUNE_X          (WIDTH*2)/3
//-----------------------------------------------
//  Level 3 Constants
//-----------------------------------------------
#define LEVEL_3_LAKE_X          (WIDTH)/3.1
//-----------------------------------------------
//  Level 4 Constants
//-----------------------------------------------
#define LEVEL_4_HILL_X          (WIDTH)/3
#define LEVEL_4_TREE_X          (WIDTH*15)/16
//-----------------------------------------------
//  Level 5 Constants
//-----------------------------------------------
#define LEVEL_5_TREE_X          (WIDTH)/2.5
//-----------------------------------------------
//  Level 6 Constants
//-----------------------------------------------
#define LEVEL_6_TREE_X          (WIDTH)/2.8
#define LEVEL_6_DUNE_X          (WIDTH*3)/4
//-----------------------------------------------
//  Level 7 Constants
//-----------------------------------------------
#define LEVEL_7_HILL_X          (WIDTH)/3
#define LEVEL_7_TREE_X          (WIDTH)/2
#define LEVEL_7_DUNE_X          (WIDTH*2)/3
//-----------------------------------------------
//  Level 8 Constants
//-----------------------------------------------
#define LEVEL_8_TREE_X          (WIDTH)/3
#define LEVEL_8_DUNE_X          (WIDTH*2)/3
//-----------------------------------------------
//  Level 9 Constants
//-----------------------------------------------
#define LEVEL_9_TREE_X          (WIDTH)/3.2
#define LEVEL_9_DUNE_X          (WIDTH)/2
#define LEVEL_9_HILL_X          (WIDTH*2)/3

typedef struct {
    int x;
    int y;
} GAMEPOINT;

typedef struct {
    GAMEPOINT topleft;
    GAMEPOINT bottomright;
} GAMERECT;

typedef struct {
    GAMEPOINT POINT1;
    GAMEPOINT POINT2;
    GAMEPOINT POINT3;
} GAMETRIANGLE;

typedef struct {
    GAMEPOINT   centre;
    int         radius;
} GAMECIRCLE;

typedef struct {
    char    name[MAX_NAME_LENGTH];
    int     score;
} GAMESCORE;

//Calculate the text width for current font
//Used to align text on buttons and leaderboard
int get_text_width(const char* text);

//Get the line hight for current font
//Used to align text on buttons
int get_line_height(void);

void filled_gametriangle(GAMETRIANGLE triangle, unsigned colour);

void filled_gamerect(GAMERECT rect, unsigned colour);

void filled_gamecircle(GAMECIRCLE circle, unsigned colour);

//Check if a point lays on the left or right side of a line formed by two other points
//Used by hit_gametriangle function to decide if the point is within the triangle
int sign(GAMEPOINT p1, GAMEPOINT p2, GAMEPOINT p3);

//Test if the circle is within the triangle
//Allow collision detection for ball with Hill
int hit_gametriangle(GAMETRIANGLE triangle, GAMECIRCLE circle);

//Test if the circle is within the rect
//Allow collision detection for ball with Tree trunk
int hit_gamerect(GAMERECT rect, GAMECIRCLE circle);

//Test if the circle is within the first circle
//Allow collision detection for ball with Tree leaves
int hit_gamecircle(GAMECIRCLE cir, GAMECIRCLE circle);

//Copies an array of object to the destination
//Deals with the memory allocation
//Help with repeated memory allocation and copying
void alocncpy(void** dest, void* from, size_t size);

//Returns the current timestamp in milliseconds
//Introduced for mouse de-bouncing which was later solved differently
//Unused at the moment, could be helpful for future update if real time is used instead of ticks
long long current_timestamp();

//Sort game scores in descending order
void sort_score(GAMESCORE *scores, int count);

#endif // COMMON_H_INCLUDED

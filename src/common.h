#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <graphics_lib.h>

//-----------------------------------------------
//  Screen Size
//-----------------------------------------------
#define WIDTH                   1200
#define HEIGHT                  675
//-----------------------------------------------
//  GAME ENVIRONMENT CONSTANTS
//-----------------------------------------------
#define GRAVITY_CONSTANT        4
#define AIR_LOSS                0.005
#define GROUND_LOSS             0.2
#define SAND_LOSS               0.5
#define HILL_LOSS               0.2
#define TREE_LOSS               0.3
#define MAX_HIT_SPEED           100
#define WIND_INFLUENCE_ON_BALL  0.05
#define WIND_INFLUENCE_ON_CLOUD 0.1
#define HILL_CONSUME_THREASHOLD 5                                       //If speed is less than this, ball will be lost in hill
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
//-----------------------------------------------
//  Object Size Standards
//-----------------------------------------------
#define CLOUD_POSITION_Y        HEIGHT/6
#define CLOUD_SIZE_STANDARD     50
#define CLOUD_SHAPE_FACTOR      1.5
#define TREE_SIZE_STANDARD      30
#define DUNE_WIDTH_STANDARD     150
#define DUNE_HEIGHT_STANDARD    75
#define LAKE_WIDTH_STANDARD     150
#define LAKE_HEIGHT_STANDARD    75
#define HILL_RADIUS_LARGE       250
#define HILL_HEIGHT_LARGE       350
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

int get_text_width(const char* text);

int get_line_height(void);

void filled_gametriangle(GAMETRIANGLE triangle, unsigned colour);

void filled_gamerect(GAMERECT rect, unsigned colour);

void filled_gamecircle(GAMECIRCLE circle, unsigned colour);

int sign(GAMEPOINT p1, GAMEPOINT p2, GAMEPOINT p3);

int hit_gametriangle(GAMETRIANGLE triangle, GAMECIRCLE circle);

int hit_gamerect(GAMERECT rect, GAMECIRCLE circle);

int hit_gamecircle(GAMECIRCLE cir, GAMECIRCLE circle);

void alocncpy(void** dest, void* from, size_t size);

#endif // COMMON_H_INCLUDED

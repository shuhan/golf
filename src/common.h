#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

//Screen Size
#define WIDTH                   1200
#define HEIGHT                  675
//Gravity constant g in m/s^2
#define GRAVITY_CONSTANT        4
//Friction constants
#define AIR_LOSS                0.005
#define GROUND_LOSS             0.2
#define SAND_LOSS               0.5
#define HILL_LOSS               0.2
#define TREE_LOSS               0.3
#define MAX_HIT_SPEED           100
#define WIND_INFLUENCE_ON_BALL  0.05
#define WIND_INFLUENCE_ON_CLOUD 0.1
#define HILL_CONSUME_THREASHOLD 5       //If speed is less than this, ball will be lost in hill

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

#endif // COMMON_H_INCLUDED

#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

//Extension of colour from Allegro wrapper
#define COLOUR_TRANSPARENT      -1

//Screen Size
#define WIDTH                   1200
#define HEIGHT                  675

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

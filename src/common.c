#include "common.h"
#include <graphics_lib.h>

int get_text_width(const char* text) {
    return al_get_text_width(GLOBAL_FONT, text);
}

int get_line_height(void) {
    return al_get_font_line_height(GLOBAL_FONT);
}

void filled_gametriangle(GAMETRIANGLE triangle, unsigned colour) {
    filled_triangle(triangle.POINT1.x, triangle.POINT1.y, triangle.POINT2.x, triangle.POINT2.y, triangle.POINT3.x, triangle.POINT3.y, colour);
}

void filled_gamerect(GAMERECT rect, unsigned colour) {
    filled_rectangle(rect.topleft.x, rect.topleft.y, rect.bottomright.x, rect.bottomright.y, colour);
}

void filled_gamecircle(GAMECIRCLE circle, unsigned colour) {
    filled_circle(circle.centre.x, circle.centre.y, circle.radius, colour);
}

int sign(GAMEPOINT p1, GAMEPOINT p2, GAMEPOINT p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

//https://www.gamedev.net/forums/topic/295943-is-this-a-better-point-in-triangle-test-2d/
int hit_gametriangle(GAMETRIANGLE triangle, GAMECIRCLE circle) {
    int d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(circle.centre, triangle.POINT1, triangle.POINT2);
    d2 = sign(circle.centre, triangle.POINT2, triangle.POINT3);
    d3 = sign(circle.centre, triangle.POINT3, triangle.POINT1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

int hit_gamerect(GAMERECT rect, GAMECIRCLE circle) {
    return  circle.centre.x + circle.radius >= rect.topleft.x &&
            circle.centre.x - circle.radius <= rect.bottomright.x &&
            circle.centre.y + circle.radius >= rect.topleft.y &&
            circle.centre.y - circle.radius <= rect.bottomright.y;
}

int hit_gamecircle(GAMECIRCLE cir, GAMECIRCLE circle) {
    return sqrt(pow(cir.centre.x - circle.centre.x, 2) + pow(cir.centre.y - circle.centre.y, 2)) <= cir.radius + circle.radius;
}

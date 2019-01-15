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

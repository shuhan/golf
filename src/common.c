#include "common.h"
#include <graphics_lib.h>

int get_text_width(const char* text) {
    return al_get_text_width(GLOBAL_FONT, text);
}

int get_line_height(void) {
    return al_get_font_line_height(GLOBAL_FONT);
}

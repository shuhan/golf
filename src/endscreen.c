#include "endscreen.h"
#include <graphics_lib.h>

void endscreen_update(ENDSCREEN *screen) {

    if(event_key_down()) {
        char letter = event.keyboard.keycode + 64;
        if((letter >= 65) && (letter <= 90) && strlen(screen->name) < (MAX_NAME_LENGTH - 1)) {
            char str[8];
            sprintf(str, "%c", letter);
            strcat(screen->name, str);
        }

        if(event.keyboard.keycode == KEYBOARD_BACKSPACE && strlen(screen->name) > 0) {
            screen->name[strlen(screen->name) - 1] = 0; //Remove last character
        }

        if(event.keyboard.keycode == KEYBOARD_ENTER_KEY && strlen(screen->name) > 0 && screen->on_completed) {
            screen->on_completed(*screen);
        }
    }
}

void endscreen_paint(ENDSCREEN screen) {
    setbkcolor(LIGHTBLUE);

    ground_paint(&(screen.ground));

    setcolor(TEXTBOX_FORECOLOUR);

    int left    = (WIDTH - TEXTBOX_WIDTH)/2;
    int top     = (HEIGHT-TEXTBOX_HEIGHT)/2;

    filled_rectangle(left, top, left + TEXTBOX_WIDTH, top + TEXTBOX_HEIGHT, TEXTBOX_COLOUR);
    rectangle(left, top, left + TEXTBOX_WIDTH, top + TEXTBOX_HEIGHT, 1);

    int line_height = get_line_height();
    int text_width  = get_text_width(screen.name);
    outtextxy(left + ((TEXTBOX_WIDTH - text_width) / 2), top + ((TEXTBOX_HEIGHT - line_height) / 2), screen.name);

    setcolor(DARKDIRT);
    outtextxy(left, top - line_height - SCORE_TEXT_OFFSET, "Please Enter Your Name: ");
}

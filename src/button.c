#include "button.h"

void gamebutton_paint(GAMEBUTTON button) {

    setcolor(button.fore_colour);

    filled_rectangle(button.left, button.top, button.left + button.width, button.top + button.height, button.back_colour);
    rectangle(button.left, button.top, button.left + button.width, button.top + button.height, 1);

    int line_height = get_line_height();
    int text_width  = get_text_width(button.text);

    outtextxy(button.left + ((button.width - text_width) / 2), button.top + ((button.height - line_height) / 2), button.text);
}

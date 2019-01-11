
#include <graphics_lib.h>
#include <amio_lib.h>

#include "common.h"
#include "button.h"

void print_x(GAMEBUTTON x);

int main(void) {

    initwindow(WIDTH, HEIGHT);
    initfont();

    cleardevice();

    GAMEBUTTON button;
    button.back_colour  = GREEN;
    button.fore_colour  = WHITE;
    button.hback_colour = BLUE;
    button.hback_colour = YELLOW;
    button.width        = 200;
    button.height       = 30;
    button.top          = (HEIGHT - button.height) / 2;
    button.left         = (WIDTH - button.width) / 2;
    strcpy(button.text, "Start");
    button.on_click = print_x;

    gamebutton_paint(button);

    update_display();

    printf("Press any key to close");

    getch();

    closegraph();

    return 0;
}

void print_x(GAMEBUTTON x) {
    printf("Name of X is %s\n", x.text);
}

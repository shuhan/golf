
#include <graphics_lib.h>
#include <amio_lib.h>

#include "common.h"
#include "button.h"

void print_x(GAMEBUTTON x);

int main(void) {

    initwindow(WIDTH, HEIGHT);
    initfont();
    initkeyboard();
    initmouse();
    create_event_queue();
    reg_keyboard_events();
    reg_mouse_events();

    cleardevice();

    GAMEMENU menu;

    GAMEBUTTON button;
    button.back_colour  = DARKGRAY;
    button.fore_colour  = WHITE;
    button.hback_colour = BLUE;
    button.hfore_colour = YELLOW;
    button.width        = 200;
    button.height       = 30;
    button.top          = (HEIGHT - button.height) / 2;
    button.left         = (WIDTH - button.width) / 2;
    strcpy(button.text, "Start");
    button.highlight    = 0;
    button.on_click = print_x;

    GAMEBUTTON buttons[1] = { button };

    menu.buttons        = buttons;
    menu.button_count   = 1;

    while(true) {

        cleardevice();

        //Wait for mouse event
        wait_for_event();
        //Process mouse event
        gamemenu_check_mouse(menu);

        gamemenu_paint(menu);

        update_display();

        //Pause for must be fairly small otherwise we will miss events
        pausefor(10);

        //Wait for keyboard event
        wait_for_event();

        if(event_key_down_arrow()) {
            break;
        }
    }

    closekeyboard();
    closegraph();

    return 0;
}

void print_x(GAMEBUTTON x) {
    printf("Name of X is %s\n", x.text);
}

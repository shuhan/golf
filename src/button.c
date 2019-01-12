#include "button.h"
#include <graphics_lib.h>

void gamebutton_paint(GAMEBUTTON button) {

    int fore_colour = button.fore_colour, back_colour = button.back_colour;

    if(button.highlight) {
        fore_colour = button.hfore_colour;
        back_colour = button.hback_colour;
    }

    setcolor(fore_colour);

    filled_rectangle(button.left, button.top, button.left + button.width, button.top + button.height, back_colour);
    rectangle(button.left, button.top, button.left + button.width, button.top + button.height, 1);

    int line_height = get_line_height();
    int text_width  = get_text_width(button.text);

    outtextxy(button.left + ((button.width - text_width) / 2), button.top + ((button.height - line_height) / 2), button.text);
}

void gamemenu_paint(GAMEMENU menu) {

    /*
        Shall have additional paint events as well to prepare the menu
        There shall be some fixed drawing logics at the moment
    */
    setbkcolor(LIGHTBLUE);

    int i;

    for(i = 0; i < menu.button_count; i++) {
        gamebutton_paint(menu.buttons[i]);
    }
}

int gamebutton_mousein(GAMEBUTTON button) {
    return XMOUSE > button.left &&
           XMOUSE < button.left + button.width &&
           YMOUSE > button.top &&
           YMOUSE < button.top + button.height;
}

void gamemenu_check_mouse(GAMEMENU menu) {
    int i;

    get_mouse_coordinates();

    for(i = 0; i < menu.button_count; i++) {

        if(gamebutton_mousein(menu.buttons[i])) {
            menu.buttons[i].highlight = 1;

            if(event_mouse_left_button_down()) {                //If mouse button is down, fire the click event
                mouse_state++;                                  //Event is fired on mouse down and up, there fore keep count to make sure a down and up is required for a click
                if(mouse_state >= 2) {
                    if(menu.buttons[i].on_click) menu.buttons[i].on_click(menu.buttons[i]);
                    mouse_state = 0;                            //Reset mouse state once click is counted
                }
                event.mouse.button = 0;                         //Nasty hack stop event from sticking
            }

        } else {
            menu.buttons[i].highlight = 0;
            mouse_state = 0;                                    //Reset mouse state so that a mouse down and up require on the same button to be counted as a click
        }
    }
}

#include "button.h"
#include "weather.h"
#include <graphics_lib.h>

void gamebutton_paint(GAMEBUTTON button) {

    if(!button.visible) return;             //If button hidden, don't need to paint

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

void gamemenu_paint(GAMEMENU menu, GAMEWEATHER weather) {

    setbkcolor(LIGHTBLUE);

    ground_paint(&(menu.ground));

    int i;

    for(i = 0; i < menu.cloud_count; i++) {
        cloud_influence(menu.clouds + i, weather, WIND_INFLUENCE_ON_CLOUD);
        cloud_paint(menu.clouds[i]);
    }

    for(i = 0; i < menu.dune_count; i++) {
        dune_paint(menu.dunes + i);
    }

    for(i = 0; i < menu.lake_count; i++) {
        lake_paint(menu.lakes + i);
    }

    for(i = 0; i < menu.tree_count; i++) {
        tree_paint(menu.trees + i);
    }

    for(i = 0; i < menu.button_count; i++) {
        gamebutton_paint(menu.buttons[i]);
    }
}

int gamebutton_mousein(GAMEBUTTON button) {
    return button.visible &&
           XMOUSE > button.left &&
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
                menu.buttons[i].mouse_state++;                  //Event is fired on mouse down and up, there fore keep count to make sure a down and up is required for a click
                if(menu.buttons[i].mouse_state >= 2) {
                    if(menu.buttons[i].on_click) menu.buttons[i].on_click(menu.buttons[i]);
                    menu.buttons[i].mouse_state = 0;            //Reset mouse state once click is counted
                }
                event.mouse.button = 0;                         //Nasty hack stop event from sticking
            }

        } else {
            menu.buttons[i].highlight = 0;
            menu.buttons[i].mouse_state = 0;                    //Reset mouse state so that a mouse down and up require on the same button to be counted as a click
        }
    }
}

void gamemenu_destroy(GAMEMENU *menu) {
    if(menu->clouds) {
        free(menu->clouds);
    }
    if(menu->trees) {
        free(menu->trees);
    }
    if(menu->dunes) {
        free(menu->dunes);
    }
    if(menu->lakes) {
        free(menu->lakes);
    }
    if(menu->buttons) {
        free(menu->buttons);
    }
}

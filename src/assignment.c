
#include <graphics_lib.h>
#include <amio_lib.h>

#include "common.h"
#include "button.h"
#include "cloud.h"
#include "weather.h"
#include "animation.h"
#include "ground.h"

void print_x(GAMEBUTTON x);
void test_hit(void);

ANIMATIONFRAME frames[4] = {
    {"data/res/0.png", 0, 0, 0},
    {"data/res/1.png", 0, 0, 0},
    {"data/res/2.png", 0, 0, 1},
    {"data/res/3.png", 0, 0, 0}};

ANIMATIONCLIP clip = {
    600, HEIGHT - 200, frames, 4, 0.05, 0, 0
};

int main(void) {

    initwindow(WIDTH, HEIGHT);
    initfont();
    initkeyboard();
    initmouse();
    create_event_queue();
    reg_keyboard_events();
    reg_mouse_events();

    gameweather_init();
    cloud_init(WIDTH);

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

    CLOUD cloud = { 400, 200, 50, 1.5 };

    GROUND ground = {WIDTH, HEIGHT, (HEIGHT * 2) / 3, (HEIGHT * 3) / 4 };

    char bitmap_path[300] = "data/res/win.png";

    BITMAP bmp = load_bitmap(bitmap_path);

    clip.on_activation = test_hit;
    animation_init(&clip);

    while(true) {

        cleardevice();

        //Wait for mouse event
        //Use allegro function directly as there is no reliable function in the wrapper
        al_wait_for_event_timed(event_queue, &event, 0.00);

        ground_paint(ground);

        draw_bitmap(bmp, 200, HEIGHT - 200);

        animation_update(&clip);

        animation_paint(&clip);

        //Process mouse event
        gamemenu_check_mouse(menu);

        gamemenu_paint(menu);

        cloud_influence(&cloud, gameweather_now(), 0.1);

        cloud_paint(cloud);

        update_display();

        //Pause for must be fairly small otherwise we will miss events
        pausefor(1);

        if(event_key('x')) {
            break;
        }
    }

    animation_destroy(&clip);
    destroy_bitmap(bmp);
    closekeyboard();
    closegraph();

    return 0;
}

void test_hit(void) {
    printf("Ball Hit\n");
}

void print_x(GAMEBUTTON x) {
    printf("Name of X is %s\n", x.text);
    animation_reset(&clip);
    clip.play = 1;
}

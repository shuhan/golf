
#include <graphics_lib.h>
#include <amio_lib.h>

#include "common.h"
#include "ball.h"
#include "button.h"
#include "cloud.h"
#include "weather.h"
#include "animation.h"
#include "ground.h"
#include "meters.h"
#include "tree.h"
#include "lake.h"
#include "dune.h"
#include "hill.h"
#include "hole.h"
#include "golf.h"

int main(void) {
    GOLF golf;

    golf_init(&golf);

    while(true) {

        if(!golf_update(&golf)) break;

        golf_paint(&golf);

        if(event_key('x')) {
            break;
        }
    }

    golf_destroy(&golf);

    return 0;
}

/*
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

BALL *ball_ref;
METER *meter_ref;

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
    button.back_colour  = DARKDIRT;
    button.fore_colour  = WHITE;
    button.hback_colour = GRASS;
    button.hfore_colour = WHITE;
    button.width        = 250;
    button.height       = 40;
    button.top          = (HEIGHT - button.height) / 2;
    button.left         = (WIDTH - button.width) / 2;
    strcpy(button.text, "Start");
    button.highlight    = 0;
    button.on_click = print_x;

    GAMEBUTTON buttons[1] = { button };

    menu.buttons        = buttons;
    menu.button_count   = 1;

    CLOUD cloud = { 400, 200, 50, 1.5 };

    GROUND ground = {WIDTH, HEIGHT, (HEIGHT * 2) / 3, (HEIGHT * 5) / 6 };

    clip.on_activation = test_hit;
    animation_init(&clip);

    METER meter = {800, ground.ground_line, 100, 0, 89, YELLOW, BLACK, 0.3, 20};
    meter.selecting = 1;
    meter_ref   = &meter;

    meter_init(&meter);

    TREE tree = {600, ground.ground_line, 30};
    DUNE dune = {600, ground.ground_line, 150, 75 };
    LAKE lake = {600, ground.ground_line, 150, 75 };
    HILL hill = {800, ground.ground_line, 250, 350, 0.3 };
    HOLE hole = {1000, ground.ground_line, 30, 15};
    BALL ball = {{{200, ground.ground_line}, 10}, BALL_STATIC, 0};
    ball_ref  = &ball;
    clip.left = ball.shape.centre.x - 40;
    clip.top  = ground.ground_line - 55;

    while(true) {

        cleardevice();

        //Wait for mouse event
        //Use allegro function directly as there is no reliable function in the wrapper
        al_wait_for_event_timed(event_queue, &event, 0.00);

        ground_paint(&ground);

        hill_paint(&hill);

        hole_paint(&hole);

        //tree_paint(&tree);

        //dune_paint(&dune);

        //lake_paint(&lake);

        if(ball_update(&ball, gameweather_now(), WIND_INFLUENCE_ON_BALL)) {
            ground_hit(ground, &ball);
            hill_hit(hill, &ball);
        }

        ball_paint(&ball);

        animation_update(&clip);

        animation_paint(&clip);

        //Process mouse event
        gamemenu_check_mouse(menu);

        gamemenu_paint(menu, gameweather_now());

        cloud_influence(&cloud, gameweather_now(), WIND_INFLUENCE_ON_CLOUD);

        cloud_paint(cloud);

        meter_update(&meter);

        meter_paint_strength(meter);

        update_display();

        //Pause for must be fairly small otherwise we will miss events
        pausefor(1);

        if(event_key('x')) {
            break;
        }
    }

    animation_destroy(&clip);
    closekeyboard();
    closemouse();
    closegraph();

    return 0;
}

void test_hit(void) {
    printf("Ball Hit\n");
    meter_ref->selecting = 0;
    ball_hit(ball_ref, MAX_HIT_SPEED * (meter_ref->current_reading / 100), 3.1416 / 3);
}

void print_x(GAMEBUTTON x) {
    printf("Name of X is %s\n", x.text);

    if(clip.current_frame == 0)
        clip.play = 1;
    else {
        animation_reset(&clip);
        ball_ref->state = BALL_ON_GROUND;
        ball_ref->horizontal_speed = 0;
        ball_ref->vertical_speed = 0;
        ball_ref->shape.centre.x = clip.left + 40;
        ball_ref->shape.centre.y = clip.top + 55;
        meter_ref->selecting = 1;
    }
}
*/

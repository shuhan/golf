#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "ground.h"
#include "tree.h"
#include "lake.h"
#include "dune.h"
#include "hill.h"
#include "cloud.h"
#include "weather.h"

int mouse_state;                        //Mouse event fires on down and up, a click is down followed by up

typedef struct {

    long    left;                       //Left corner of the button
    long    top;                        //Top corner of the button
    char    text[32];                   //Button text
    long    width;                      //Width in pixel
    long    height;                     //Height in pixel
    int     back_colour;                //Background colour
    int     fore_colour;                //Foreground/Text colour
    int     hback_colour;               //Highlight (Active state) background colour
    int     hfore_colour;               //Highlight (Active state) foreground colour
    void    (*on_click)(GAMEBUTTON);    //On click event
    char    highlight;                  //If it shall be highlighted
    char    visible;
} GAMEBUTTON;

typedef struct {
    GAMEBUTTON *buttons;
    int         button_count;
    GROUND      ground;
    TREE        *trees;
    int         tree_count;
    LAKE        *lakes;
    int         lake_count;
    DUNE        *dunes;
    int         dune_count;
    CLOUD       *clouds;
    int         cloud_count;
} GAMEMENU;

void gamemenu_paint(GAMEMENU menu, GAMEWEATHER weather);

void gamebutton_paint(GAMEBUTTON button);

int gamebutton_mousein(GAMEBUTTON button);

void gamemenu_check_mouse(GAMEMENU menu);

#endif // BUTTON_H_INCLUDED

#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <graphics_lib.h>

typedef struct {

    POINT   location;       //Top left corner of the button
    char    text[32];       //Button text
    long    width;          //Width in pixel
    long    height;         //Height in pixel
    int     back_colour;    //Background colour
    int     fore_colour;    //Foreground/Text colour
    int     hback_colour;   //Highlight (Active state) background colour
    int     hfore_colour;   //Highlight (Active state) foreground colour
    int     tab_index;      //Tab or up down button order

} GAMEBUTTON;

#endif // BUTTON_H_INCLUDED

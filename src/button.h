#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <graphics_lib.h>

typedef struct {

    POINT   location;
    char    text[32];
    long    width;
    long    height;
    int     background;
    int     colour;

} GAMEBUTTON;

#endif // BUTTON_H_INCLUDED

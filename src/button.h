#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

typedef struct {

    long    top;                        //Top corner of the button
    long    left;                       //Left corner of the button
    char    text[32];                   //Button text
    long    width;                      //Width in pixel
    long    height;                     //Height in pixel
    int     back_colour;                //Background colour
    int     fore_colour;                //Foreground/Text colour
    int     hback_colour;               //Highlight (Active state) background colour
    int     hfore_colour;               //Highlight (Active state) foreground colour
    void    (*on_click)(GAMEBUTTON);    //On click event
    char    highlight;                  //If it shall be highlighted

} GAMEBUTTON;

typedef struct {
    GAMEBUTTON *buttons;
    int         button_count;
} GAMEMENU;

void gamemenu_paint(GAMEMENU menu);

void gamebutton_paint(GAMEBUTTON button);

int gamebutton_mousein(GAMEBUTTON button);

void gamemenu_check_mouse(GAMEMENU menu);

#endif // BUTTON_H_INCLUDED

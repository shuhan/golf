#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <graphics_lib.h>
#include "common.h"

typedef struct {
    char            frame_path[300];
    int             xoffset;
    int             yoffset;
    char            shall_activate;             //If animation action shall be executed on this frame
    BITMAP          frame;
} ANIMATIONFRAME;


typedef struct {
    int             left;                       //Animation left corner
    int             top;                        //Animation top corner
    ANIMATIONFRAME  frames[MAX_FRAME_COUNT];    //Fixed max frame count for now
    int             frame_count;                //Number of frame in the animation
    float           incriment_rate;             //How many frame changes on every tick, it can be smaller than 1
    char            loop;                       //If animation shall loop
    char            play;
    int             current_frame;              //Current frame is the floor of frame_progress and max value is current_frame - 1
    float           frame_progress;             //Frame progress can be a fraction which means frame changes every couple of ticks
    void            (*on_activation)(void);     //On activation event
} ANIMATIONCLIP;

void animation_init(ANIMATIONCLIP *animation);

void animation_reset(ANIMATIONCLIP *animation);

void animation_update(ANIMATIONCLIP *animation);

void animation_paint(ANIMATIONCLIP *animation);

void animation_destroy(ANIMATIONCLIP *animation);

#endif // ANIMATION_H_INCLUDED

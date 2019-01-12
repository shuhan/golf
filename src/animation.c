#include "animation.h"
#include <graphics_lib.h>

void animation_init(ANIMATIONCLIP *animation) {
    int i = 0;

    for(i = 0; i < animation->frame_count; i++) {
        animation->frames[i].frame = load_bitmap(animation->frames[i].frame_path);
    }

    animation->current_frame    = 0;
    animation->frame_progress   = 0;
    animation->play = 0;
}

void animation_reset(ANIMATIONCLIP *animation) {
    animation->current_frame    = 0;
    animation->frame_progress   = 0;
    animation->play = 0;
}

void animation_update(ANIMATIONCLIP *animation) {
    if(animation->play) {
        animation->frame_progress   += animation->incriment_rate;

        int new_current_frame = floor(animation->frame_progress);
        //If animation has action
        //animation's next frame shall activate the action
        //and frame is changed
        //activate the action
        if(animation->on_activation &&
           new_current_frame > animation->current_frame &&
           new_current_frame < animation->frame_count &&
           animation->frames[new_current_frame].shall_activate)
            animation->on_activation();

        animation->current_frame = new_current_frame;

        if(animation->current_frame >= animation->frame_count) {
            if(animation->loop) {
                animation->frame_progress = 0;
                animation->current_frame = 0;
            } else {
                animation->current_frame--;     //Revert back to last frame
                animation->play = 0;
            }
        }
    }
}

void animation_paint(ANIMATIONCLIP *animation) {
    draw_bitmap(animation->frames[animation->current_frame].frame,
                animation->left + animation->frames[animation->current_frame].xoffset,
                animation->top + animation->frames[animation->current_frame].yoffset);
}

void animation_destroy(ANIMATIONCLIP *animation) {
    int i = 0;

    for(i = 0; i < animation->frame_count; i++) {
        destroy_bitmap(animation->frames[i].frame);
    }

    animation->play = 0;
}

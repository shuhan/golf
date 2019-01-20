#ifndef ENDSCREEN_H_INCLUDED
#define ENDSCREEN_H_INCLUDED

#include "common.h"
#include "ground.h"

typedef struct {
    GROUND ground;
    char name[MAX_NAME_LENGTH];
    int  score;

    void (*on_completed)(ENDSCREEN);
} ENDSCREEN;

void endscreen_update(ENDSCREEN *screen);

void endscreen_paint(ENDSCREEN screen);

#endif // ENDSCREEN_H_INCLUDED

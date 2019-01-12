#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED

typedef struct {
    int width;
    int height;
    int top_line;
    int ground_line;

} GROUND;

void ground_paint(GROUND ground);

#endif // GROUND_H_INCLUDED

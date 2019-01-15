#include "ground.h"
#include "graphics_lib.h"

void ground_paint(GROUND *ground) {

    filled_rectangle(0, ground->top_line, ground->width, ground->height, GRASS);
}

int ground_hit(GROUND ground, BALL *ball) {

}

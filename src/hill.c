#include "hill.h"
#include <graphics_lib.h>

void hill_bound(HILL *hill) {

    GAMETRIANGLE t0 = {{hill->x - hill->radius, hill->y}, {hill->x, hill->y - hill->height}, {hill->x + hill->radius, hill->y}};
    hill->peaks[0] = t0;
    GAMETRIANGLE t1 = {{hill->x - (hill->radius * (1 - hill->peak_distance)), hill->y}, {hill->x + (hill->radius * hill->peak_distance), hill->y - hill->height}, {hill->x + (hill->radius * (1 + hill->peak_distance)), hill->y}};
    hill->peaks[1] = t1;
}

void hill_paint(HILL *hill) {

    hill_bound(hill);

    filled_gametriangle(hill->peaks[0], DIRT);
    filled_gametriangle(hill->peaks[1], DIRT);

}

int hill_hit(HILL hill, BALL *ball) {

}

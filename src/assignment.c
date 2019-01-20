
#include <graphics_lib.h>
#include <amio_lib.h>

#include "common.h"
#include "ball.h"
#include "button.h"
#include "cloud.h"
#include "weather.h"
#include "animation.h"
#include "ground.h"
#include "meters.h"
#include "tree.h"
#include "lake.h"
#include "dune.h"
#include "hill.h"
#include "hole.h"
#include "golf.h"
#include "leaderboard.h"

int main(void) {

    GOLF golf;

    golf_init(&golf);

    while(true) {

        if(!golf_update(&golf)) break;

        golf_paint(&golf);

        pausefor(1);
    }

    golf_destroy(&golf);

    return 0;
}

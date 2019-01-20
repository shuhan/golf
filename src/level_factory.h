#ifndef LEVEL_FACTORY_H_INCLUDED
#define LEVEL_FACTORY_H_INCLUDED

#include <graphics_lib.h>
#include "level.h"
#include "common.h"

void create_game_levels(GAMELEVEL levels[NUMBER_OF_LEVELS], void (*on_activation)(void), void (*on_stop)(BALL), void (*on_complete)(void));

#endif // LEVEL_FACTORY_H_INCLUDED

#ifndef CLOUD_H_INCLUDED
#define CLOUD_H_INCLUDED

#include "weather.h"

typedef struct {
    float x;
    float y;
    int size;
    float shape_factor;
    //Calculated read only property, only updated after it's drawn
    int left;
    int right;
    int cloud_radius;
} CLOUD;

int cloud_window_width;

void cloud_init(int window_width);

void cloud_calculate(CLOUD *cloud);

void cloud_influence(CLOUD *cloud, GAMEWEATHER weather, float influence_rate);

void cloud_paint(CLOUD cloud);

#endif // CLOUDE_H_INCLUDED

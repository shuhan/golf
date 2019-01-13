#ifndef METERS_H_INCLUDED
#define METERS_H_INCLUDED


typedef struct {
    int     left;
    int     top;
    int     size;
    float   min_reading;
    float   max_reading;
    int     colour;
    int     highlight_colour;
    float   speed_factor;
    int     width;
    float   current_reading;
    char    selecting;
    char    direction;
} METER;

void meter_init(METER *meter);

void meter_update(METER *meter);

void meter_paint_angle(METER meter);

void meter_paint_strength(METER meter);

#endif // METERS_H_INCLUDED

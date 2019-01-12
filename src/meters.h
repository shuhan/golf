#ifndef METERS_H_INCLUDED
#define METERS_H_INCLUDED


typedef struct {
    int     left;
    int     top;
    int     size;
    int     min_reading;
    int     max_reading;
    int     colour;
    int     highlight_colour;
    float   speed_factor;
    int     current_reading;
    char    selecting;
} METER;

void meter_update(METER *meter);

void meter_paint_angle(METER meter);

void meter_paint_speed(METER meter);

#endif // METERS_H_INCLUDED

#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

typedef struct {
    char    airspeed;              //Speed of the air in meter per second 1m/s - 10m/s
    char    direction;             //Direction of air speed 1 for left to right and -1 for right to left
    int     next_weather_change;   //Random variable to indicate when then weather shall change next time (500 - 2000)
} GAMEWEATHER;

GAMEWEATHER _weather;

void gameweather_init();

GAMEWEATHER gameweather_now();

#endif // WEATHER_H_INCLUDED

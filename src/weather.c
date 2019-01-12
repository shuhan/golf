#include "weather.h"

void gameweather_init() {

    _weather.airspeed = floor(random_number(100, 1000) / 100);     //Pick a random number between 1 to 10 but an scaling up and down is used to make the distribution even
    if(random_number(0, 1000) >= 500) {
        _weather.direction = 1;
    } else {
        _weather.direction = -1;
    }
    _weather.next_weather_change = random_number(500, 2000);
}

GAMEWEATHER gameweather_now() {

    _weather.next_weather_change--;

    if(_weather.next_weather_change <= 0) {
        gameweather_init();
    }

    return _weather;
}

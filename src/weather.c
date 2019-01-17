#include "weather.h"

void gameweather_init() {
    //srand(time(0));
    _weather.airspeed = floor(random_number(0, 500) / 100);     //Pick a random number between 0 to 5 but an scaling up and down is used to make the distribution even
    if(random_number(0, 1000) >= 500) {
        _weather.direction = 1;
    } else {
        _weather.direction = -1;
    }
    _weather.next_weather_change = random_number(1000, 5000);
}

GAMEWEATHER gameweather_now() {

    _weather.next_weather_change--;

    if(_weather.next_weather_change <= 0) {
        gameweather_init();
    }

    return _weather;
}

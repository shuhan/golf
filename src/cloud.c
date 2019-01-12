#include "cloud.h"
#include <graphics_lib.h>

void cloud_init(int window_width) {
    cloud_window_width = window_width;
}

void cloud_calculate(CLOUD *cloud) {
    int height              = cloud->size;
    int width               = cloud->size * cloud->shape_factor;
    int small_width         = height;
    int small_height        = small_width / cloud->shape_factor;

    cloud->cloud_radius     = width + small_width;
    cloud->left             = cloud->x - cloud->cloud_radius;
    cloud->right            = cloud->x + cloud->cloud_radius;
}

void cloud_influence(CLOUD *cloud, GAMEWEATHER weather, float influence_rate) {
    cloud_calculate(cloud);

    cloud->x += weather.airspeed * weather.direction * influence_rate;

    if(weather.direction == 1 && cloud->left > cloud_window_width) cloud->x = (-1 * cloud->cloud_radius);
    if(weather.direction == -1 && cloud->right < 0) cloud->x = cloud_window_width + cloud->cloud_radius;
}

void cloud_paint(CLOUD cloud) {
    int height          = cloud.size;
    int width           = cloud.size * cloud.shape_factor;
    int small_width     = height;
    int small_height    = small_width / cloud.shape_factor;

    filled_ellipse(cloud.x, cloud.y, width, height, WHITE);
    filled_ellipse(cloud.x - width, cloud.y, small_width, small_height, WHITE);
    filled_ellipse(cloud.x + width, cloud.y, small_width, small_height, WHITE);
}

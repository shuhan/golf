#include "meters.h"

void meter_init(METER *meter) {
    meter->current_reading = meter->min_reading;
    meter->direction = 1;
}

void meter_update(METER *meter) {
    if(meter->selecting) {
        if(meter->direction) {
            meter->current_reading += meter->speed_factor;
            if(meter->current_reading + meter->speed_factor > meter->max_reading) {
                meter->direction = 0;
            }
        } else {
            meter->current_reading -= meter->speed_factor;
            if(meter->current_reading - meter->speed_factor < meter->min_reading) {
                meter->direction = 1;
            }
        }
    }
}

void meter_paint_angle(METER meter) {
    setcolor(meter.colour);
    arc(meter.left, meter.top, meter.size, meter.min_reading, (-1) * meter.max_reading, meter.width);
    setcolor(meter.highlight_colour);
    arc(meter.left, meter.top, meter.size, meter.min_reading, (-1) * meter.current_reading, meter.width);
    if(meter.current_reading > meter.min_reading) {
        setcolor(meter.colour);
        arc(meter.left, meter.top, meter.size, meter.min_reading, (-1) * (meter.current_reading - 4), meter.width);
    }
}

void meter_paint_strength(METER meter) {
    filled_rectangle(meter.left, meter.top - meter.size, meter.left + meter.width, meter.top, meter.colour);
    int current = ((meter.size)*((meter.current_reading)/(meter.max_reading - meter.min_reading)));
    filled_rectangle(meter.left, meter.top - current, meter.left + meter.width, meter.top, meter.highlight_colour);
}

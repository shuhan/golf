#include "meters.h"

void meter_update(METER *meter) {

}

void meter_paint_angle(METER meter) {
    setcolor(meter.colour);
    arc(meter.left, meter.top, meter.size, meter.min_reading, meter.max_reading, meter.size * 0.1);
    setcolor(meter.highlight_colour);
    arc(meter.left, meter.top, meter.size, meter.min_reading, meter.current_reading, meter.size * 0.1);
    if(meter.current_reading > meter.min_reading) {
        setcolor(meter.colour);
        arc(meter.left, meter.top, meter.size, meter.min_reading, meter.current_reading - 1, meter.size * 0.1);
    }
}

void meter_paint_speed(METER meter) {

}

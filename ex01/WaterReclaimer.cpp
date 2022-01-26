#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() :
    _water(0),
    _started(false)
{
}

void    WaterReclaimer::start()
{
    _started = true;
    if (_water == 0) {
        MissionCriticalError err("Not enough water to achieve the mission.", "WaterReclaimer");
        throw(err);
    }

}

void    WaterReclaimer::useWater(int water)
{
    if (_started == false) {
        UserError err("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
        throw(err);
    }
    if (water < 0) {
        UserError err("Water use should be positif.", "WaterReclaimer");
        throw(err);
    }
    if (water > _water || _water - water < 10) {
        LifeCriticalError err("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
        throw(err);
    }
    _water -= water;
}

void    WaterReclaimer::generateWater()
{
    if (_water > 90) {
        NasaError err("Cannot generate water, reclaimer already full.", "WaterReclaimer");
        throw(err);
    }
    _water += 10;
}

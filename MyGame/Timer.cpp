#include "Timer.h"
#include "BasicFunction.h"
Timer::Timer()
{
    start_tick = 0;
    pause_tick = 0;
    starting = false;
}

Timer::~Timer()
{

}

void Timer::start()
{
    starting = true;
    start_tick = SDL_GetTicks();
}


int Timer::get_ticks()
{
    if (is_started() == true)
    {
        return SDL_GetTicks() - start_tick;
    }

    return 0;
}

bool Timer::is_started()
{
    return starting;
}

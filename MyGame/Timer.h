#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer();
    ~Timer();

    void start();

    int get_ticks();

    bool is_started();


private:
    int start_tick;
    int pause_tick;

    bool starting;
};

#endif // TIMER_H

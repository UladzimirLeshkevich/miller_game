#include "count_for_timer.hxx"

void count_for_timer(int& min, int& min2, int& sec, int& sec2)
{
    sec++;

    if (sec >= 10)
    {
        sec2++;
        sec = 0;
    }
    if (sec2 >= 6)
    {
        min++;
        sec2 = 0;
    }
    if (min >= 10)
    {
        min2++;
        min = 0;
    }
    if (min2 >= 6)
    {
        min2 = 0;
    }
}

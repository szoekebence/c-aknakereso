#include "timer.h"
#include <time.h>

time_t kezdet;
time_t vege;

void ora_indul()
{
    kezdet=time(NULL);
}

void ora_leall()
{
    vege=time(NULL);
}

time_t stopper()
{
    return vege-kezdet;
}

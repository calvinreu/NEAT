#pragma once
#include <time.h>
#include <random>

inline int random_int()
{
    srand(time(NULL));
    return rand();
}

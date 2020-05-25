#pragma once
#include "population.hpp"
#include <extended/vector>


namespace NEAT
{
    using extended::vector;
    size_t GLOBALinputC;
    size_t GLOBALoutputC;

    extern void learn(NEAT::population &population);

} // namespace NEAT

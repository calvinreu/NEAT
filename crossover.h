#pragma once

#include "genom.hpp"

namespace NEAT {
    //parent 1 is stronger than 2
    extern NEAT::NNetGene crossover(const NEAT::NNetGene &parent1, const NEAT::NNetGene &parent2);

}
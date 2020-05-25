#pragma once

#include "genome.hpp"
#include "random.hpp"
#include "activationFunctions.hpp"

namespace NEAT{

    //returns mutated parent gene and adds Innovation to populationGene if necessary
    extern NEAT::NNetGene mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &populationGene, const size_t &mutationRate);
    extern void nodeMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene, const size_t &connection);
    extern void connectionMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene);

}
#pragma once

#include "genom.hpp"

namespace NEAT{

    //returns mutated parent gene and adds inovation to populationGene if necessary
    extern NEAT::NNetGene mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &populationGene);
    extern void nodeMutation(const NEAT::vector<NEAT::PrivateNodeInovation> &nodeGenes);
    
}
#pragma once

#include "genom.hpp"

namespace NEAT{

    //returns mutated parent gene and adds inovation to populationGene if necessary
    extern NEAT::NNetGene mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &populationGene, const size_t &mutationRate);
    extern void nodeMutation(const NEAT::vector<NEAT::PrivateNodeInovation> &parent, NEAT::vector<NEAT::PrivateNodeInovation> &child);
    extern void connectionMutation(const NEAT::vector<NEAT::PrivateNodeInovation> &parent, NEAT::vector<NEAT::PrivateNodeInovation> &child);
    
}
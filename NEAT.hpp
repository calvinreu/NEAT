#pragma once
#include <nnet/neural_network.hpp>
#include <extended/vector>
#include "genom.hpp"

namespace NEAT{

    using extended::vector;

    struct NNet
    {
        nnet::neural_network NNet;
        NEAT::genes NNetGenes;
    };
    
    struct population
    {
        vector<NEAT::NNet> NNets;
    };
    
}

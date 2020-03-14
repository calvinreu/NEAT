#pragma once
#include <nnet/neural_network.hpp>
#include <extended/vector>
#include "genom.hpp"

namespace NEAT{

    using extended::vector;

    struct population
    {
        vector<nnet::neural_network> NNets;
        vector<NEAT::NNetGene> genePool;

        vector<nnet::neural_network> parentNNets;
        vector<NEAT::NNetGene> parentGenes;
        NEAT::PublicGene GlobalGenes;

        population(const size_t &populationSize, const size_t &parentC);
        void setMutation();
    };
}

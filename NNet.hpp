#pragma once
#include <nnet/neural_network.hpp>
#include <extended/vector>
#include "genom.hpp"

namespace NEAT{

    size_t GLOBALinputC;
    size_t GLOBALoutputC;

    using extended::vector;

    struct NNetInfo
    {
        nnet::neural_network_info NNET;
        NEAT::genes NNetGenes;
    };

    struct population
    {
        vector<NEAT::genes> NNetGenes;
        vector<nnet::neural_network> NNets;
        vector<NEAT::NNetInfo> parents;

        population(const size_t &populationSize, const size_t &parentC);
        void setMutation(vector<NEAT::NNetInfo> &&mutations);
        const vector<NEAT::NNetInfo>& getParents(const NEAT::vector<size_t> &parentI);
    };
}

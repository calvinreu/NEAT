#pragma once
#include <nnet/neural_network.hpp>
#include <extended/vector>
#include "genom.hpp"

namespace NEAT{

    using extended::vector;

    struct NNetInfo
    {
        nnet::neural_network_info NNET;
        NEAT::genes NNetGenes;
        double score;
    };

    class population
    {
    private:
        vector<nnet::neural_network> NNets;
        vector<NEAT::NNetInfo> parents;
    public:
        population(const size_t &populationSize, const size_t &parentC);
        void AssignScore(const NEAT::vector<double> &score);
        const vector<NEAT::NNetInfo>& getParents();
    };
}

#include "population.hpp"

NEAT::population::population(const size_t &populationSize, const size_t &parentC)
:   genePool(populationSize),
    NNets(populationSize),
    parentNNets(parentC),
    parentGenes(parentC)
{}

void NEAT::population::setMutation()
{
    
    if(genePool.size() != NNets.max_size() - NNets.size())//vector memory - parentC look at get parents
        throw("Warning: NNets.max_size() different vector size NNets.size() in function population::setMutation");

    for(auto i =  genePool.begin(); i < genePool.end(); i++)
        NNets.push(NEAT::getNNetConstructionInfo(*i));
}

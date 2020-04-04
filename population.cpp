#include "population.hpp"

NEAT::population::population(const size_t &populationSize, const size_t &parentC)
:   genePool(populationSize),
    NNets(populationSize),
    parentNNets(parentC),
    parentGenes(parentC)
{}
/*
const vector<NEAT::NNetInfo>& NEAT::population::getParents(const NEAT::vector<size_t> &parentI)
{
    if (parentI.size() != parents.size())
        throw("different vector size: population::getParents");

    NEAT::NNetInfo currentParent;
    vector<nnet::neural_network> parentNNet(parents.size());

    for (size_t i = 0; i < parents.size(); i++)
    {
        currentParent.NNET = NNets[parentI[i]].get_info();
        //currentParent.NNetGenes = NNetGenes[parentI[i]];
        parents[parentI[i]] = currentParent;
        parentNNet.push(std::move(parentI[i]));
    }
    
    NNets.free(NNets.size());
    //NNetGenes.free(NNetGenes.size());

    for (size_t i = 0; i < parents.size(); i++)
    {
        NNets.push(std::move(parentNNet[i]));
        //NNetGenes.push<const genes&>(parents[i].NNetGenes);
    }
    
    return parents;
}
*/

void NEAT::population::setMutation()
{
    
    if(genePool.size() != NNets.max_size() - NNets.size())//vector memory - parentC look at get parents
        throw("Warning: NNets.max_size() different vector size NNets.size() in function population::setMutation");

    for(auto i =  genePool.begin(); i < genePool.end(); i++)
        NNets.push(NEAT::getNNetConstructionInfo(*i));
}

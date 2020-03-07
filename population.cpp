#include "population.hpp"

NEAT::population::population(const size_t &populationSize, const size_t &parentC)
{
    NNets.add_memory(populationSize);
    parents.assign(parentC);
}

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

void NEAT::population::setMutation(vector<NEAT::NNetInfo> &mutations)
{
    
    if(mutations.size() != NNets.max_size() - parents.size())//vector memory - parentC look at get parents
        throw("different vector size: population::setMutation");

    for(auto i =  mutations.begin(); i < mutations.end(); i++)
    {
        NNets.push<const nnet::neural_network_info&>(i->NNET);
        //NNetGenes.push(std::move(i->NNetGenes));
    }
}

//template<typename T>
//void NEAT::population::setInovationNumber(T &InovationNumber)
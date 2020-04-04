#include "genom.hpp"

size_t* NEAT::NNetGene::firstNodeInovation = nullptr;
NEAT::ConnectionInovation* NEAT::NNetGene::firstConnectionInovation = nullptr;

nnet::neural_network_info&& NEAT::getNNetConstructionInfo(const NEAT::NNetGene &genom)
{
    nnet::neural_network_info NNetConstructionInfo;

    NNetConstructionInfo.hiddenLayer.add_memory(genom.nodeInovation.size());
    NNetConstructionInfo.inputLayer .add_memory(genom.inputNodes   .size());
    NNetConstructionInfo.outputLayer.add_memory(genom.outputNodes  .size());

    for (auto i = genom.inputNodes.begin(); i < genom.inputNodes.end(); i++)
        NNetConstructionInfo.inputLayer.push(*i);

    for (auto i = genom.outputNodes.begin(); i < genom.outputNodes.end(); i++)
        NNetConstructionInfo.outputLayer.push(*i);

    for (auto i = genom.nodeInovation.begin(); i < genom.nodeInovation.end(); i++)
        NNetConstructionInfo.hiddenLayer.push(i->akt);
    
    vector<size_t> hiddenConnectionC(genom.nodeInovation.size());//ammount of connections for every neuron
    vector<size_t> outputConnectionC(genom.outputNodes  .size());
    hiddenConnectionC.assign<size_t>(genom.nodeInovation.size(), 0);
    outputConnectionC.assign<size_t>(genom.outputNodes  .size(), 0);

    for (auto i = genom.connectionInovation.begin(); i < genom.connectionInovation.end(); i++)
    {
        if (i->connectionInovation->endLayer == nnet::output)
            outputConnectionC[i->connectionInovation->endNode]++;
        else
            hiddenConnectionC[i->connectionInovation->endNode]++;
    }
    
    for (size_t i = 0; i < outputConnectionC.size(); i++)
        NNetConstructionInfo.outputLayer[i].connections.add_memory(outputConnectionC[i]);

    for (size_t i = 0; i < hiddenConnectionC.size(); i++)
        NNetConstructionInfo.hiddenLayer[i].connections.add_memory(hiddenConnectionC[i]);
    
    for (auto i = genom.connectionInovation.begin(); i < genom.connectionInovation.end(); i++)
    {
        if (i->connectionInovation->endLayer == nnet::output)
            NNetConstructionInfo.outputLayer[i->connectionInovation->endNode].connections.push(
                i->connectionInovation->beginLayer,
                i->connectionInovation->beginNode,
                i->weight);
        else
            NNetConstructionInfo.hiddenLayer[i->connectionInovation->endNode].connections.push(
                i->connectionInovation->beginLayer,
                i->connectionInovation->beginNode,
                i->weight);
    }

    return std::move(NNetConstructionInfo);

}
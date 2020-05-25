#include "genome.hpp"

size_t* NEAT::NNetGene::firstNodeInnovation = nullptr;
NEAT::ConnectionInnovation* NEAT::NNetGene::firstConnectionInnovation = nullptr;
extern const size_t publicGeneConnectionPushSize;
extern const size_t publicGeneNodePushSize;

nnet::neural_network_info NEAT::getNNetConstructionInfo(const NEAT::NNetGene &genome)
{
    nnet::neural_network_info NNetConstructionInfo;

    NNetConstructionInfo.hiddenLayer.add_memory(genome.nodeInnovation.size());
    NNetConstructionInfo.inputLayer .add_memory(genome.inputNodes   .size());
    NNetConstructionInfo.outputLayer.add_memory(genome.outputNodes  .size());

    for (auto i = genome.inputNodes.begin(); i < genome.inputNodes.end(); i++)
        NNetConstructionInfo.inputLayer.push(*i);

    for (auto i = genome.outputNodes.begin(); i < genome.outputNodes.end(); i++)
        NNetConstructionInfo.outputLayer.push(*i);

    for (auto i = genome.nodeInnovation.begin(); i != genome.nodeInnovation.end(); i++)
        NNetConstructionInfo.hiddenLayer.push(i->akt);
    
    vector<size_t> hiddenConnectionC(genome.nodeInnovation.size());//ammount of connections for every neuron
    vector<size_t> outputConnectionC(genome.outputNodes  .size());
    hiddenConnectionC.assign<size_t>(genome.nodeInnovation.size(), 0);
    outputConnectionC.assign<size_t>(genome.outputNodes  .size(), 0);

    for (auto i = genome.connectionInnovation.begin(); i != genome.connectionInnovation.end(); i++)
    {
        if (i->connectionInnovation->endLayer == nnet::output)
            outputConnectionC[i->connectionInnovation->endNode]++;
        else
            hiddenConnectionC[i->connectionInnovation->endNode]++;
    }
    
    for (size_t i = 0; i < outputConnectionC.size(); i++)
        NNetConstructionInfo.outputLayer[i].connections.add_memory(outputConnectionC[i]);

    for (size_t i = 0; i < hiddenConnectionC.size(); i++)
        NNetConstructionInfo.hiddenLayer[i].connections.add_memory(hiddenConnectionC[i]);
    
    for (auto i = genome.connectionInnovation.begin(); i != genome.connectionInnovation.end(); i++)
    {
        if (i->connectionInnovation->endLayer == nnet::output)
            NNetConstructionInfo.outputLayer[i->connectionInnovation->endNode].connections.push(
                i->connectionInnovation->beginLayer,
                i->connectionInnovation->beginNode,
                i->weight);
        else
            NNetConstructionInfo.hiddenLayer[i->connectionInnovation->endNode].connections.push(
                i->connectionInnovation->beginLayer,
                i->connectionInnovation->beginNode,
                i->weight);
    }

    return NNetConstructionInfo;

}

size_t* NEAT::PublicGene::addNodeGene(const size_t &nodeGene)
{
    for (auto i = nodeInnovations.begin(); i < nodeInnovations.end(); i++)
        if(*i == nodeGene)
            return &i;

    if (nodeInnovations.size() == nodeInnovations.max_size())
        nodeInnovations.add_memory(publicGeneNodePushSize);

    nodeInnovations.push(nodeGene);
    return &nodeInnovations.last();
}

NEAT::ConnectionInnovation* NEAT::PublicGene::addConnectionGene(const NEAT::ConnectionInnovation &connectionGene)
{
    for (auto i = connectionInnovation.begin(); i < connectionInnovation.end(); i++)
        if(*i == connectionGene)
            return &i;

    if (connectionInnovation.size() == connectionInnovation.max_size())
        connectionInnovation.add_memory(publicGeneConnectionPushSize);
    
    connectionInnovation.push(connectionGene);
    return &connectionInnovation.last();
}
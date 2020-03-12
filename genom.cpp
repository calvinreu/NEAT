#include "genom.hpp"

nnet::neural_network_info& NEAT::getNNetConstructionInfo(const NEAT::NNetGene &genom)
{
    nnet::neural_network_info NNetConstructionInfo;

    NNetConstructionInfo.hiddenLayer.add_memory(genom.NodeInovation.size());
    NNetConstructionInfo.inputLayer .add_memory(genom.inputLayerS );
    NNetConstructionInfo.outputLayer.add_memory(genom.outputLayerS);

    for (auto i = 0; i < ; i++)
    {
        /* code */
    }
    
}
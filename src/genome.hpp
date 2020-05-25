#pragma once
#include <nnet/info_objects.hpp>
#include <set>
#include <extended/vector>

extern const size_t publicGeneNodeBufferSize;
extern const size_t publicGeneConnectionBufferSize;

namespace NEAT{

    using extended::vector;

    struct ConnectionInnovation
    {
        nnet::layer beginLayer; 
        size_t beginNode;//Innovation number hidden Node
        
        nnet::layer endLayer; 
        size_t endNode;//Innovation number hidden Node

        bool operator==(const NEAT::ConnectionInnovation &other) { return (beginLayer == other.beginLayer && beginNode == other.beginNode && endLayer == other.endLayer && endNode == other.endNode); }
    };

    struct PrivateNodeInnovation
    {
        const size_t* nodeInnovation;
        double(*akt)(const double&);
        bool active = false;

        PrivateNodeInnovation(const size_t* nodeInnovation, double(*akt)(const double&)):nodeInnovation(nodeInnovation), akt(akt){}
        bool operator<(const NEAT::PrivateNodeInnovation &other) const { return this->nodeInnovation < other.nodeInnovation; }
    };
    
    struct PrivateConnectionInnovation
    {
        const NEAT::ConnectionInnovation* connectionInnovation;
        double weight;
        bool active = true;

        PrivateConnectionInnovation(const NEAT::ConnectionInnovation* connectionInnovation, const double &weight):connectionInnovation(connectionInnovation), weight(weight){}
        bool operator<(const NEAT::PrivateConnectionInnovation &other) const { return this->connectionInnovation < other.connectionInnovation; }
    };

    struct NNetGene
    {
        NEAT::vector<double(*)(const double&)> inputNodes;
        NEAT::vector<double(*)(const double&)> outputNodes;
        std::set<NEAT::PrivateNodeInnovation> nodeInnovation;
        std::set<NEAT::PrivateConnectionInnovation> connectionInnovation;
        static size_t* firstNodeInnovation;
        static NEAT::ConnectionInnovation* firstConnectionInnovation;
    };

    struct PublicGene
    {
        NEAT::vector<size_t> nodeInnovations;//contains connection Innovation numberson which the nodes were created on
        NEAT::vector<NEAT::ConnectionInnovation> connectionInnovation;

        //needs perfomance enhancement for allocating memory
        size_t* addNodeGene(const size_t &nodeGene);
        NEAT::ConnectionInnovation* addConnectionGene(const NEAT::ConnectionInnovation &connectionGene);

        PublicGene(): nodeInnovations(publicGeneConnectionBufferSize){}
    };

    extern nnet::neural_network_info getNNetConstructionInfo(const NEAT::NNetGene &genome);
}
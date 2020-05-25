#pragma once
#include <nnet/info_objects.hpp>
#include <set>
#include <extended/vector>

namespace NEAT{

    using extended::vector;

    struct ConnectionInovation
    {
        nnet::layer beginLayer; 
        size_t beginNode;//inovation number hidden Node
        
        nnet::layer endLayer; 
        size_t endNode;//inovation number hidden Node

        bool operator==(const NEAT::ConnectionInovation &other) { return (beginLayer == other.beginLayer && beginNode == other.beginNode && endLayer == other.endLayer && endNode == other.endNode); }
    };

    struct PrivateNodeInovation
    {
        const size_t* nodeInovation;
        double(*akt)(const double&);
        bool active = false;

        PrivateNodeInovation(const size_t* nodeInovation, double(*akt)(const double&)):nodeInovation(nodeInovation), akt(akt){}
        bool operator<(const NEAT::PrivateNodeInovation &other) const { return this->nodeInovation < other.nodeInovation; }
    };
    
    struct PrivateConnectionInovation
    {
        const NEAT::ConnectionInovation* connectionInovation;
        double weight;
        bool active = true;

        PrivateConnectionInovation(const NEAT::ConnectionInovation* connectionInovation, const double &weight):connectionInovation(connectionInovation), weight(weight){}
        bool operator<(const NEAT::PrivateConnectionInovation &other) const { return this->connectionInovation < other.connectionInovation; }
    };

    struct NNetGene
    {
        NEAT::vector<double(*)(const double&)> inputNodes;
        NEAT::vector<double(*)(const double&)> outputNodes;
        std::set<NEAT::PrivateNodeInovation> nodeInovation;
        std::set<NEAT::PrivateConnectionInovation> connectionInovation;
        static size_t* firstNodeInovation;
        static NEAT::ConnectionInovation* firstConnectionInovation;
    };

    struct PublicGene
    {
        NEAT::vector<size_t> nodeInovations;//contains connection inovation numberson which the nodes were created on
        NEAT::vector<NEAT::ConnectionInovation> connectionInovation;

        //needs perfomance enhancement for allocating memory
        size_t* addNodeGene(const size_t &nodeGene);
        NEAT::ConnectionInovation* addConnectionGene(const NEAT::ConnectionInovation &connectionGene);
    };

    extern nnet::neural_network_info getNNetConstructionInfo(const NEAT::NNetGene &genom);
}
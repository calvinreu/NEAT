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
    };

    struct PrivateNodeInovation
    {
        const size_t* nodeInovation;
        double(*akt)(const double&);
        bool active = false;

        bool operator<(const NEAT::PrivateNodeInovation &other) const { return this->nodeInovation < other.nodeInovation; }
    };
    
    struct PrivateConnectionInovation
    {
        const NEAT::ConnectionInovation* connectionInovation;
        double weight;
        bool active = true;

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
    };

    extern nnet::neural_network_info getNNetConstructionInfo(const NEAT::NNetGene &genom);
}
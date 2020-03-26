#pragma once
#include <nnet/info_objects.hpp>
#include <extended/vector>


namespace NEAT{

    using extended::vector;

    struct ConnectionInovation
    {
        nnet::layer beginLayer; 
        size_t beginNode;
        
        nnet::layer endLayer; 
        size_t endNode;
    };

    struct PrivateNodeInovation
    {
        size_t* nodeInovation;
        double(*akt)(const double&);
    };
    
    struct PrivateConnectionInovation
    {
        const NEAT::ConnectionInovation* connectionInovation;
        double weight;
    };

    struct NNetGene
    {
        NEAT::vector<double(*)(const double&)> inputNodes;
        NEAT::vector<double(*)(const double&)> outputNodes;
        NEAT::vector<NEAT::PrivateNodeInovation> nodeInovation;
        NEAT::vector<NEAT::PrivateConnectionInovation> connectionInovation;
        static size_t* firstNodeInovation;
        static NEAT::ConnectionInovation* firstConnectionInovation;
    };

    size_t* NNetGene::firstNodeInovation = nullptr;
    NEAT::ConnectionInovation* NNetGene::firstConnectionInovation = nullptr;

    struct PublicGene
    {
        NEAT::vector<size_t> nodeInovations;//contains connection inovation numberson which the nodes were created on
        NEAT::vector<NEAT::ConnectionInovation> connectionInovation;
    };

    extern nnet::neural_network_info& getNNetConstructionInfo(const NEAT::NNetGene &genom);
}
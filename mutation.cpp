#include "mutation.hpp"

extern const size_t WeightMutationChance;
extern const size_t AddNodeChance;//per connection
extern const size_t AddConnectionChance;
extern const size_t ProbabilityPrecision;
extern const double MinRandomWeight;
extern const double MaxRandomWeight;
 
NEAT::NNetGene NEAT::mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &publicGene)
{
    NEAT::NNetGene child = parent;

    if(random_int()%ProbabilityPrecision < WeightMutationChance)
        NEAT::changeWeight(parent,child);
    
    for(size_t i = 0; i < parent.connectionInovation.size(); i++)
        if(random_int()%ProbabilityPrecision < AddNodeChance)
            NEAT::nodeMutation(parent, child, publicGene, i);
    
    if (random_int()%ProbabilityPrecision < AddConnectionChance)
        NEAT::connectionMutation(parent, child, publicGene);
}

void NEAT::nodeMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene, const size_t &connection)
{
    size_t* nodeCreated = publicGene.addNodeGene(connection);

    //check if this node is already in this NN
    if(parent.nodeInovation.find(NEAT::PrivateNodeInovation(nodeCreated, nullptr)) == parent.nodeInovation.end())
        return;

    child.nodeInovation.insert(NEAT::PrivateNodeInovation(nodeCreated, 
        (double(*)(const double&))(ActFunc::getAktFunc())));

    //connection going to the new node
    child.connectionInovation.insert(NEAT::PrivateConnectionInovation(
        publicGene.addConnectionGene(NEAT::ConnectionInovation{
            .beginLayer = publicGene.connectionInovation[connection].beginLayer,
            .beginNode  = publicGene.connectionInovation[connection].beginNode, 
            .endLayer   = nnet::hidden,
            .endNode    = nodeCreated-child.firstNodeInovation}),
        random_double(MinRandomWeight, MaxRandomWeight)));

    //connection going away from the new node
    child.connectionInovation.insert(NEAT::PrivateConnectionInovation(
        publicGene.addConnectionGene(NEAT::ConnectionInovation{
            .beginLayer = nnet::hidden, 
            .beginNode  = nodeCreated-child.firstNodeInovation,
            .endLayer   = publicGene.connectionInovation[connection].endLayer,
            .endNode    = publicGene.connectionInovation[connection].endNode}),
        random_double(MinRandomWeight, MaxRandomWeight)));
    
    *(const_cast<bool*>(&child.connectionInovation.find(NEAT::PrivateConnectionInovation(&(publicGene.connectionInovation[*nodeCreated]), 0))->active)) = false;
    //change active attribute which is constant because it is in set
}

void NEAT::connectionMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene)
{
    NEAT::ConnectionInovation newConnection;

    if (random_int()%2 == 0)
    {
        newConnection.beginLayer = nnet::input;
        newConnection.beginNode  = random_int()%child.inputNodes.size();
    }else{
        newConnection.beginLayer = nnet::hidden;
        newConnection.beginNode  = random_int()%child.nodeInovation.size();
    }

    if (random_int()%2 == 0)
    {
        newConnection.endLayer = nnet::output;
        newConnection.endNode  = random_int()%child.outputNodes.size();
    }else{
        newConnection.endLayer = nnet::hidden;
        newConnection.endNode  = random_int()%child.nodeInovation.size();
    }

    child.connectionInovation.insert(NEAT::PrivateConnectionInovation(publicGene.addConnectionGene(newConnection), random_double(MinRandomWeight, MaxRandomWeight)));
}
#include "mutation.hpp"

extern const size_t WeightRandomizeChance;
extern const size_t WeightChangeChance;
extern const double WeightChangeMax;
extern const double WeightChangeMin;
extern const size_t AddNodeChance;//per connection
extern const size_t AddConnectionChance;
extern const size_t ProbabilityPrecision;
extern const double MinRandomWeight;
extern const double MaxRandomWeight;
 
NEAT::NNetGene NEAT::mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &publicGene)
{
    NEAT::NNetGene child = parent;
        
    
    {
        auto itParent = parent.connectionInnovation.begin();
        auto itChild  = child.connectionInnovation.begin();

        for(size_t i = 0; i < parent.connectionInnovation.size(); i++)
        {
            if(random_int()%ProbabilityPrecision < AddNodeChance)
                NEAT::nodeMutation(parent, child, publicGene, i);

            if(random_int()%ProbabilityPrecision < WeightRandomizeChance)
                (const_cast<NEAT::PrivateConnectionInnovation*>(&(*itChild)))->weight = random_double(MinRandomWeight, MaxRandomWeight);
            else if(random_int()&ProbabilityPrecision < WeightChangeChance)
                (const_cast<NEAT::PrivateConnectionInnovation*>(&(*itChild)))->weight = (const_cast<NEAT::PrivateConnectionInnovation*>(&(*itParent)))->weight + random_double(WeightChangeMin, WeightChangeMax);

            itChild++;
            itParent++;
        }
    }
    
    if (random_int()%ProbabilityPrecision < AddConnectionChance)
        NEAT::connectionMutation(parent, child, publicGene);
}

void NEAT::nodeMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene, const size_t &connection)
{
    size_t* nodeCreated = publicGene.addNodeGene(connection);

    //check if this node is already in this NN
    if(parent.nodeInnovation.find(NEAT::PrivateNodeInnovation(nodeCreated, nullptr)) == parent.nodeInnovation.end())
        return;

    child.nodeInnovation.insert(NEAT::PrivateNodeInnovation(nodeCreated, 
        (double(*)(const double&))(ActFunc::getAktFunc())));

    //connection going to the new node
    child.connectionInnovation.insert(NEAT::PrivateConnectionInnovation(
        publicGene.addConnectionGene(NEAT::ConnectionInnovation{
            .beginLayer = publicGene.connectionInnovation[connection].beginLayer,
            .beginNode  = publicGene.connectionInnovation[connection].beginNode, 
            .endLayer   = nnet::hidden,
            .endNode    = nodeCreated-child.firstNodeInnovation}),
        random_double(MinRandomWeight, MaxRandomWeight)));

    //connection going away from the new node
    child.connectionInnovation.insert(NEAT::PrivateConnectionInnovation(
        publicGene.addConnectionGene(NEAT::ConnectionInnovation{
            .beginLayer = nnet::hidden, 
            .beginNode  = nodeCreated-child.firstNodeInnovation,
            .endLayer   = publicGene.connectionInnovation[connection].endLayer,
            .endNode    = publicGene.connectionInnovation[connection].endNode}),
        random_double(MinRandomWeight, MaxRandomWeight)));
    
    *(const_cast<bool*>(&child.connectionInnovation.find(NEAT::PrivateConnectionInnovation(&(publicGene.connectionInnovation[*nodeCreated]), 0))->active)) = false;
    //change active attribute which is constant because it is in set
}

void NEAT::connectionMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene)
{
    NEAT::ConnectionInnovation newConnection;

    if (random_int()%2 == 0)
    {
        newConnection.beginLayer = nnet::input;
        newConnection.beginNode  = random_int()%child.inputNodes.size();
    }else{
        newConnection.beginLayer = nnet::hidden;
        newConnection.beginNode  = random_int()%child.nodeInnovation.size();
    }

    if (random_int()%2 == 0)
    {
        newConnection.endLayer = nnet::output;
        newConnection.endNode  = random_int()%child.outputNodes.size();
    }else{
        newConnection.endLayer = nnet::hidden;
        newConnection.endNode  = random_int()%child.nodeInnovation.size();
    }

    child.connectionInnovation.insert(NEAT::PrivateConnectionInnovation(publicGene.addConnectionGene(newConnection), random_double(MinRandomWeight, MaxRandomWeight)));
}
#include "mutation.h"

extern const size_t WeightMutationChance;
extern const size_t AddNodeChance;//per connection
extern const size_t AddConnectionChance;
extern const size_t ProbabilityPrecision;
 
NEAT::NNetGene NEAT::mutate(const NEAT::NNetGene &parent, NEAT::PublicGene &publicGene)
{
    NEAT::NNetGene child;

    if(random_int()%ProbabilityPrecision < WeightMutationChance)
        NEAT::changeWeight(parent,child);
    
    for(size_t i = 0; i < parent.connectionInovation.size(); i++)
        if(random_int()%ProbabilityPrecision < AddNodeChance)
            NEAT::nodeMutation(parent, child, publicGene, i);
    
    if (random_int()%ProbabilityPrecision < AddConnectionChance)
        NEAT::connectionMutation(parent, child);
}

void NEAT::nodeMutation(const NEAT::NNetGene &parent, NEAT::NNetGene &child, NEAT::PublicGene &publicGene, const size_t &connection)
{
    child.nodeInovation.push(NEAT::PrivateNodeInovation(publicGene.addNodeGene(connection), (double(*)(const double&))(ActFunc::getAktFunc())));
    
}
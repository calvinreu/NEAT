#include "crossover.h"

NEAT::NNetGene NEAT::crossover(const NEAT::NNetGene &parent1, const NEAT::NNetGene &parent2)
{
    NEAT::NNetGene child;
    child.inputNodes = parent1.inputNodes;
    child.outputNodes = parent1.outputNodes;

    {
        auto iParent1 = parent1.nodeInnovation.begin(), iParent2 = parent2.nodeInnovation.begin();
        for (size_t* i = parent1.firstNodeInnovation; i <= parent1.nodeInnovation.rbegin()->nodeInnovation; i++)
        {
            if(iParent1->nodeInnovation == i)
            {
                child.nodeInnovation.insert(*iParent1);
                iParent1++;

                if (iParent2->nodeInnovation == i)
                    iParent2++;

            }
            else if(iParent2->nodeInnovation == i)
            {
                child.nodeInnovation.insert(*iParent2);
                iParent2++;
            }
        }
    }
    
    {
        auto iParent1 = parent1.connectionInnovation.begin(), iParent2 = parent2.connectionInnovation.begin();

        for (auto i = parent1.firstConnectionInnovation; i <= parent1.connectionInnovation.rbegin()->connectionInnovation; i++)
        {
            if(iParent1->connectionInnovation == i)
            {
                if(iParent1->active)
                    child.connectionInnovation.insert(*iParent1);
                
                iParent1++;

                if (iParent2->connectionInnovation == i)
                    iParent2++;

            }
            else if(iParent2->connectionInnovation == i)
            {
                child.connectionInnovation.insert(*iParent2);
                iParent2++;
            }
        }
    }
    
    return child;
}
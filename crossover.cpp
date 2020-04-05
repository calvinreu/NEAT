#include "crossover.h"

NEAT::NNetGene NEAT::crossover(const NEAT::NNetGene &parent1, const NEAT::NNetGene &parent2)
{
    NEAT::NNetGene child;
    child.inputNodes = parent1.inputNodes;
    child.outputNodes = parent1.outputNodes;

    {
        auto iParent1 = parent1.nodeInovation.begin(), iParent2 = parent2.nodeInovation.begin();
        for (size_t* i = parent1.firstNodeInovation; i <= parent1.nodeInovation.rbegin()->nodeInovation; i++)
        {
            if(iParent1->nodeInovation == i)
            {
                child.nodeInovation.insert(*iParent1);
                iParent1++;

                if (iParent2->nodeInovation == i)
                    iParent2++;

            }
            else if(iParent2->nodeInovation == i)
            {
                child.nodeInovation.insert(*iParent2);
                iParent2++;
            }
        }
    }
    
    {
        auto iParent1 = parent1.connectionInovation.begin(), iParent2 = parent2.connectionInovation.begin();

        for (auto i = parent1.firstConnectionInovation; i <= parent1.connectionInovation.rbegin()->connectionInovation; i++)
        {
            if(iParent1->connectionInovation == i)
            {
                child.connectionInovation.insert(*iParent1);
                iParent1++;

                if (iParent2->connectionInovation == i)
                    iParent2++;

            }
            else if(iParent2->connectionInovation == i)
            {
                child.connectionInovation.insert(*iParent2);
                iParent2++;
            }
        }
    }
    
    return child;
}
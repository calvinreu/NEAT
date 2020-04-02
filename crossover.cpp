#include "crossover.h"

NEAT::NNetGene NEAT::crossover(const NEAT::NNetGene &parent1, const NEAT::NNetGene &parent2)
{
    NEAT::NNetGene child;
    size_t currentElementParent1 = 0, currentElementParent2 = 0;

    child.inputNodes = parent1.inputNodes;
    child.outputNodes = parent1.outputNodes;

    child.nodeInovation.add_memory(parent1.nodeInovation.size() + parent2.nodeInovation.size());
    child.connectionInovation.add_memory(parent1.connectionInovation.size() + parent2.connectionInovation.size());

    for (size_t* i = parent1.firstNodeInovation; i <= parent1.nodeInovation.last().nodeInovation; i++)
    {
        if(parent1.nodeInovation[currentElementParent1].nodeInovation == i)
        {
            child.nodeInovation.push(parent1.nodeInovation[currentElementParent1]);
            currentElementParent1++;

            if (parent2.nodeInovation[currentElementParent2].nodeInovation == i)
                currentElementParent2++;
            
        }
        else if(parent2.nodeInovation[currentElementParent2].nodeInovation == i)
        {
            child.nodeInovation.push(parent2.nodeInovation[currentElementParent2]);
            currentElementParent2++;
        }
    }

    //this would take to much performance to justify the gained memory
    //child.nodeInovation.free_memory(child.nodeInovation.max_size() - child.nodeInovation.size());

    currentElementParent1 = 0, currentElementParent2 = 0;
    
    for (auto* i = parent1.firstConnectionInovation; i <= parent1.connectionInovation.last().connectionInovation; i++)
    {
        if(parent1.connectionInovation[currentElementParent1].connectionInovation == i)
        {
            child.connectionInovation.push(parent1.connectionInovation[currentElementParent1]);
            currentElementParent1++;

            if (parent2.connectionInovation[currentElementParent2].connectionInovation == i)
                currentElementParent2++;
            
        }
        else if(parent2.connectionInovation[currentElementParent2].connectionInovation == i)
        {
            child.connectionInovation.push(parent2.connectionInovation[currentElementParent2]);
            currentElementParent2++;
        }
    }

    //this would take to much performance to justify the gained memory
    //child.connectionInovation.free_memory(child.connectionInovation.max_size() - child.connectionInovation.size());
    
    return child;
}
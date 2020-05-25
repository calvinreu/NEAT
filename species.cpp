#include "species.hpp"

extern const double DisjointImportance;
extern const double ExcessImportance;
extern const double WeightImportance;


double nnDifferenz(const NEAT::NNetGene& first, const NEAT::NNetGene& second)
{
    double score = 0;
    //nodes
    {
        auto iFirst = first.nodeInovation.begin(), iSecond = second.nodeInovation.begin();
        //check for Disjoint
        while (!(iFirst == first.nodeInovation.end() || iSecond == second.nodeInovation.end()))
        {
            if (iFirst->nodeInovation > iSecond->nodeInovation)
            {
                score+=DisjointImportance;
                iSecond++;
            }
            else if(iFirst->nodeInovation < iSecond->nodeInovation)
            {
                score+=DisjointImportance;
                iFirst++;
            }
            else
            {
                iSecond++;
                iFirst++;
            }
        }
        //excess genes
        if (iFirst == first.nodeInovation.end())
            for (iSecond; iSecond != second.nodeInovation.end(); iSecond++)
                score+=ExcessImportance;
        else
            for (iFirst; iFirst != second.nodeInovation.end(); iFirst++)
                score+=ExcessImportance;
    }
    //connections
    {
        auto iFirst = first.connectionInovation.begin(), iSecond = second.connectionInovation.begin();

        while (!(iFirst == first.connectionInovation.end() || iSecond == second.connectionInovation.end()))
        {
            if (iFirst->connectionInovation > iSecond->connectionInovation)
                iSecond++;
            else if(iFirst->connectionInovation < iSecond->connectionInovation)
                iFirst++;
            else
            {
                score+=NEAT::diff<double>(iFirst->weight, iSecond->weight);
                iSecond++;
                iFirst++;
            }
        }
    }
    
    
    
}
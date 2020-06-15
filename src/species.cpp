#include "species.hpp"

extern const double DisjointImportance;
extern const double ExcessImportance;
extern const double WeightImportance;


double nnDifferenz(const NEAT::NNetGene& first, const NEAT::NNetGene& second)
{
    double score = 0;
    //nodes
    {
        auto iFirst = first.nodeInnovation.begin(), iSecond = second.nodeInnovation.begin();
        //check for Disjoint
        while (!(iFirst == first.nodeInnovation.end() || iSecond == second.nodeInnovation.end()))
        {
            if (iFirst->nodeInnovation > iSecond->nodeInnovation)
            {
                score+=DisjointImportance;
                iSecond++;
            }
            else if(iFirst->nodeInnovation < iSecond->nodeInnovation)
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
        if (iFirst == first.nodeInnovation.end())
            for (iSecond; iSecond != second.nodeInnovation.end(); iSecond++)
                score+=ExcessImportance;
        else
            for (iFirst; iFirst != second.nodeInnovation.end(); iFirst++)
                score+=ExcessImportance;

        score /= NEAT::larger(first.nodeInnovation.size(), second.nodeInnovation.size());
    }
    //connections
    {
        auto iFirst = first.connectionInnovation.begin(), iSecond = second.connectionInnovation.begin();

        while (!(iFirst == first.connectionInnovation.end() || iSecond == second.connectionInnovation.end()))
        {
            if (iFirst->connectionInnovation > iSecond->connectionInnovation)
                iSecond++;
            else if(iFirst->connectionInnovation < iSecond->connectionInnovation)
                iFirst++;
            else
            {
                score+=NEAT::diff<double>(iFirst->weight, iSecond->weight)*WeightImportance;
                iSecond++;
                iFirst++;
            }
        }
    }
}

size_t NNetC
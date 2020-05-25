#include "../crossover.h"
#include <iostream>

double aktFunc1(const double &x){ return 1; }
double aktFunc2(const double &x){ return 2; }

int main()
{

    NEAT::NNetGene parent1, parent2, child;
    size_t n[7];
    NEAT::ConnectionInnovation c[7];
    size_t* nodeInnovation1[4] = {n, n+1, n+4, n+5};
    size_t* nodeInnovation2[4] = {n+2, n+3, n+5, n+6};
    NEAT::ConnectionInnovation* connectionInnovation1[4] = {c, c+1, c+3, c+4};
    NEAT::ConnectionInnovation* connectionInnovation2[4] = {c, c+2, c+3, c+5};

    parent1.firstNodeInnovation = n;
    parent1.firstConnectionInnovation = c;

    for (size_t i = 0; i < 4; i++)
    {
        parent1.nodeInnovation.insert(NEAT::PrivateNodeInnovation{ .nodeInnovation = nodeInnovation1[i], .akt = aktFunc1});
        parent2.nodeInnovation.insert(NEAT::PrivateNodeInnovation{ .nodeInnovation = nodeInnovation2[i], .akt = aktFunc2});
        parent1.connectionInnovation.insert(NEAT::PrivateConnectionInnovation{ .connectionInnovation = connectionInnovation1[i], .weight = 1});
        parent2.connectionInnovation.insert(NEAT::PrivateConnectionInnovation{ .connectionInnovation = connectionInnovation2[i], .weight = 2});
    }

    child = NEAT::crossover(parent1, parent2);

    std::cout << "parent1:\nnode:akt\n";

    for (auto i = parent1.nodeInnovation.begin(); i != parent1.nodeInnovation.end(); i++)
        std::cout << i->nodeInnovation << ":" << i->akt(0) << std::endl;

    std::cout << "connection\n";

    for (auto i = parent1.connectionInnovation.begin(); i != parent1.connectionInnovation.end(); i++)
        std::cout << i->connectionInnovation << ":" << i->weight << std::endl;



    std::cout << "parent2:\nnode:akt\n";

    for (auto i = parent2.nodeInnovation.begin(); i != parent2.nodeInnovation.end(); i++)
        std::cout << i->nodeInnovation << ":" << i->akt(0) << std::endl;

    std::cout << "connection\n";

    for (auto i = parent2.connectionInnovation.begin(); i != parent2.connectionInnovation.end(); i++)
        std::cout << i->connectionInnovation << ":" << i->weight << std::endl;
    


    std::cout << "child:\nnode:akt\n";

    for (auto i = child.nodeInnovation.begin(); i != child.nodeInnovation.end(); i++)
        std::cout << i->nodeInnovation << ":" << i->akt(0) << std::endl;

    std::cout << "connection\n";

    for (auto i = child.connectionInnovation.begin(); i != child.connectionInnovation.end(); i++)
        std::cout << i->connectionInnovation << ":" << i->weight << std::endl;
}
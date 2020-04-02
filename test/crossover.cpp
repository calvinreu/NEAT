#include "../crossover.cpp"
#include <iostream>

double aktFunc1(const double &x){ return 1; }
double aktFunc2(const double &x){ return 2; }

int main()
{

    NEAT::NNetGene parent1, parent2, child;
    parent1.nodeInovation.add_memory(4);
    parent2.nodeInovation.add_memory(4);
    parent1.connectionInovation.add_memory(4);
    parent2.connectionInovation.add_memory(4);
    size_t n[7];
    NEAT::ConnectionInovation c[7];
    size_t* nodeInovation1[4] = {n, n+1, n+4, n+5};
    size_t* nodeInovation2[4] = {n+2, n+3, n+5, n+6};
    NEAT::ConnectionInovation* connectionInovation1[4] = {c, c+1, c+3, c+4};
    NEAT::ConnectionInovation* connectionInovation2[4] = {c, c+2, c+3, c+5};

    parent1.firstNodeInovation = n;
    parent1.firstConnectionInovation = c;

    for (size_t i = 0; i < 4; i++)
    {
        parent1.nodeInovation.push(NEAT::PrivateNodeInovation{ .nodeInovation = nodeInovation1[i], .akt = aktFunc1});
        parent2.nodeInovation.push(NEAT::PrivateNodeInovation{ .nodeInovation = nodeInovation2[i], .akt = aktFunc2});
        parent1.connectionInovation.push(NEAT::PrivateConnectionInovation{ .connectionInovation = connectionInovation1[i], .weight = 1});
        parent2.connectionInovation.push(NEAT::PrivateConnectionInovation{ .connectionInovation = connectionInovation2[i], .weight = 2});
    }

    child = NEAT::crossover(parent1, parent2);

    std::cout << "parent1:\nnode:akt\n";

    for (size_t i = 0; i <  4; i++)
        std::cout << parent1.nodeInovation[i].nodeInovation << ":" << parent1.nodeInovation[i].akt(0) << std::endl;

    std::cout << "connection\n";

    for (size_t i = 0; i <  4; i++)
        std::cout << parent1.connectionInovation[i].connectionInovation << ":" << parent1.connectionInovation[i].weight << std::endl;



    std::cout << "parent2:\nnode:akt\n";

    for (size_t i = 0; i <  4; i++)
        std::cout << parent2.nodeInovation[i].nodeInovation << ":" << parent2.nodeInovation[i].akt(0) << std::endl;

    std::cout << "connection\n";

    for (size_t i = 0; i <  4; i++)
        std::cout << parent2.connectionInovation[i].connectionInovation << ":" << parent2.connectionInovation[i].weight << std::endl;
    


    std::cout << "child:\nnode:akt\n";

    for (auto i = child.nodeInovation.begin(); i < child.nodeInovation.end(); i++)
        std::cout << i->nodeInovation << ":" << i->akt(0) << std::endl;

    std::cout << "connection\n";

    for (auto i = child.connectionInovation.begin(); i <  child.connectionInovation.end(); i++)
        std::cout << i->connectionInovation << ":" << i->weight << std::endl;
}
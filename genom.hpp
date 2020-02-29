#include <nnet/info_objects.hpp>
#include <extended/vector>


namespace NEAT{
    using extended::vector;

    struct InovationNumberConnection
    {
        struct Begin{ nnet::layer Layer;
                      size_t Node; };
        struct End{ nnet::layer Layer;
                    size_t Node; };
        static size_t InovationNumber;
    };
    
    struct InovationNumberNode
    {
        nnet::layer Layer;
        size_t Node;
        static size_t InovationNumber;
    };

    struct genes
    {
        NEAT::vector<NEAT::InovationNumberConnection> connections;
        NEAT::vector<NEAT::InovationNumberNode> nodes;
    };
    
}
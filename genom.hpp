#include <nnet/info_objects.hpp>
#include <extended/vector>


namespace NEAT{

    using extended::vector;

    struct ConnectionInovation
    {
        struct begin
        { nnet::layer layer; size_t node; };

        struct end
        { nnet::layer layer; size_t node; };
    };

    struct PublicGene
    {
        NEAT::vector<size_t> NodeInovations;//contains connection inovation numberson which the nodes were created on
        NEAT::vector<NEAT::ConnectionInovation> ConnectionInovations;
    };

    struct NNgene
    {
        NEAT::vector<size_t*>  NodeInovation;
        NEAT::vector<NEAT::ConnectionInovation*> ConnectionInovations;
    };
}
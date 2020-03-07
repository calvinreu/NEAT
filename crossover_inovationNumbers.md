# Crossover and inovation numbers

## Node Inovation Number

    - input and output have the first inovation number
    - new nodes get inovation numbers depending on the connection they are created on
    - node genes have the inovation number of the connection they've been created on

## Connection Inovation Number

    - The inovation number of a connection is specified by the nodes it is connected to
    - The inovation number of every possible connection is stored in a seperated class and can be accessed by any neural network
    - Connections can be disabled

## Genes

    - one object which contains all gene inovations

## Crossover

    - one parent can used for multiple crossovers with different parents
    - Disjoint genes will always be in the new gene
    - the stronger parent excess genes will be added while the excess genes of the weaker parent will be deleted
    - connection settings will be adopted from the stronger parent

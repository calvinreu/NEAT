# Crossover and inovation numbers

## Node Inovation Number

- new nodes get inovation numbers depending on the connection they arecreated on
- node genes have the inovation number of the connection they've beencreated on

## Connection Inovation Number

- The inovation number of a connection is specified by the nodes it isconnected to
- The inovation number of every possible connection is stored in aseperated class and can be accessed by any neural network
- Connections can be disabled

## Genes

- one object which contains all gene inovations

## Crossover

- one parent can used for multiple crossovers with different parents
- Disjoint genes will always be in the new gene
- the stronger parent excess genes will be added while the excessgenes of the weaker parent will be deleted
- connection settings will be adopted from the stronger parent
- activation functions will be adopted from the stronger partent

## Speciation

- genetic difference is defined in [this](http://nn.cs.utexas.edu/downloads/papers/stanley.cec02.pdf) NEAT paper on page 3 under the heading _C.ProtectingInnovationthroughSpeciation_
- parents will be chosen according to the algorythm mentioned in the paper above

## suggestions

- add the neural network size to the reward function to avoid extremly big neural networks, which aren't neccesary

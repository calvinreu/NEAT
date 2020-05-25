# Crossover and innovation numbers

everything which isn't addressed in this file is done as stated in [this](http://nn.cs.utexas.edu/downloads/papers/stanley.cec02.pdf) NEAT paper. 

## Node Innovation Number

- new nodes get innovation numbers for every new hidden, input and output node. Nodes don't have innovation numbers to increase performance and simplify the code.
- node genes possess information about the connection on which they have been created.

## Connection Inovation Number

- The innovation number of a connection is specified by the nodes it is connecting.
- The information about a connection gene can be accessed by its innovation number and is available to any neural network.
- if connections are disabled, they will still be in the genome of the neural network but won't change the output of the neural network.

## Genes

- every population has one public object which contains information about every gene used by the population.

## Crossover

- One parent can be used for multiple crossovers with different parents in the same species.
- A new gene will always contain the disjoint genes from both parents
- the excess genes of the fitter will be added while the excess genes of the weaker parent won't be adapted.
- the connection data will be adopted from the stronger parent.
- activation functions can be altered by mutation.
- activation functions will be adopted from the stronger parent.

## Species

- Genetic difference is defined in [this](http://nn.cs.utexas.edu/downloads/papers/stanley.cec02.pdf) NEAT paper on page 3 under the heading _C.ProtectingInnovationthroughSpeciation_

## Suggestions

- Use the size of the neural network to change the fitness values.
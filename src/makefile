CC = g++-9 -std=c++17

genome: genome.hpp genome.cpp
	$(CC) genome.cpp -c -o genome.o

crossover: crossover.cpp crossover.h genome.o genome.hpp
	$(CC) crossover.cpp -c -o crossover.o
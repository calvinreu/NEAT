CC = g++ -std=c++17

crossover: crossover.cpp crossover.h genom.cpp genom.hpp
	$(CC) crossover.cpp -c -o crossover.o
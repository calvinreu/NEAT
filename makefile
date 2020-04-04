CC = g++ -std=c++17

genom: genom.hpp genom.cpp
	$(CC) genom.cpp -c -o genom.o

crossover: crossover.cpp crossover.h genom.o genom.hpp
	$(CC) crossover.cpp -c -o crossover.o
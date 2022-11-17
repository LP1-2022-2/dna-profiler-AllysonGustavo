#MEU MAKEFILE

PROG = dna_profiler
CC = g++
FLAGS  = -Wall -pedantic -Iinclude

$(PROG): main.o Busca.o
	$(CC) $(FLAGS) -o $(PROG) main.o

main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp

clean:
	rm *.o $(PROG)
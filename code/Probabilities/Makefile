all: programs
	./dice 
	./cards

programs: dice.o cards.o
	g++ -o dice dice.o
	gcc -o cards cards.o

programs.o: dice.cpp cards.c
	g++ -c dice.cpp
	gcc -c cards.c

clean:
	rm -f programs *.o
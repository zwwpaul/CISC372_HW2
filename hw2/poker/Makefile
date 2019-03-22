all: poker
	./poker

poker: poker.o
	gcc -g poker.o -o poker

poker.o: poker.c
	gcc -g -c poker.c

clean:
	rm -f *.o poker

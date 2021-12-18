CC = gcc
FLAGS = -Wall -g
AR=ar 

all: stringProg 
		
Ex3.o: Ex3.c 
	$(CC) $(FLAGS) -c Ex3.c
	
stringProg: Ex3.o 
	$(CC) $(FLAGS) Ex3.o -lm -o connections
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections		

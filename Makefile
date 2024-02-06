CC = gcc
CFLAGS = -Wall -g

all: connections

my_mat.o: my_mat.c my_mat.h
	gcc $(CFLAGS) -c my_mat.c

connections: main.o my_mat.o
	$(CC) $(CFLAGS) main.o my_mat.o -o connections

main.o: main.c 
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o main 

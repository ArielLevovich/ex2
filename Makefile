CC = gcc
CFLAGS = -Wall -g

all: my_graph my_Knapsack

my_mat.o: my_mat.c my_mat.h
	gcc $(CFLAGS) -c my_mat.c

my_graph: my_graph.o my_mat.o
	$(CC) $(CFLAGS) my_graph.o my_mat.o -o my_graph

my_graph.o: my_graph.c 
	gcc $(CFLAGS) -c my_graph.c

my_Knapsack: my_Knapsack.o my_mat.o
	$(CC) $(CFLAGS) my_Knapsack.o my_mat.o -o my_Knapsack

my_Knapsack.o: my_Knapsack.c 
	gcc $(CFLAGS) -c my_Knapsack.c

clean:
	rm -f *.o connections 

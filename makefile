CC = gcc #Compilador
CFLAGS = -Wall -Wextra -Werror -std=c99 -g #Banderas de compilación

interprete: interprete.c itree.o bstree.o cola.o
	$(CC) $(CFLAGS) -o interprete interprete.c cola.o bstree.o itree.o
itree.o: itree.c itree.h 
	$(CC) $(CFLAGS) -c itree.c 
bstree.o: bstree.c bstree.h
	$(CC) $(CFLAGS) -c bstree.c
cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c

CC = gcc #Compilador
CFLAGS = -Wall -Wextra -Werror -std=c99 -g #Banderas de compilación

interprete: interprete.c cola.o avl.o itree.o 
	$(CC) $(CFLAGS) -o interprete interprete.c cola.o avl.o itree.o
itree.o: itree.c itree.h 
	$(CC) $(CFLAGS) -c itree.c 
avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c
cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c

CC = gcc #Compilador
CFLAGS = -Wall -Wextra -Werror -std=c99 -g #Banderas de compilación

interprete: interprete.c cola.o itree.o -lm
	$(CC) $(CFLAGS) -o interprete interprete.c cola.o itree.o -lm
itree.o: itree.c itree.h
	$(CC) $(CFLAGS) -c itree.c
cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c

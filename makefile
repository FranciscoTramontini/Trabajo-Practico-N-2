CC = gcc #Compilador
CFLAGS = -Wall -Wextra -Werror -std=c99 -g #Banderas de compilación

cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c
itree.o: itree.c itree.h 
	$(CC) $(CFLAGS) -c itree.c 

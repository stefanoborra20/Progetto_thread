
game: main.o
	gcc -g -o game main.o -lncurses -lpthread
main.o: main.h main.c
	gcc -c -g -lncurses -lpthread main.c


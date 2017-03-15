all: window 

window: window.c
	gcc -D_REENTRANT -ggdb -Wall window.c -o window -lncurses -lpthread

clean:
	rm -f window


/*

	Lab 5 - CS3100 - threads and synchronization template
	by Cameron Pickle 

*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

WINDOW *topwin, *botwin;
pthread_t tid[2];
pthread_mutex_t ncurses;

void * countUp(void *ptr) {
	int i = 0, key;

	while (1) {
		pthread_mutex_lock(&ncurses);
		wprintw(topwin, "Count up: %d\n", i++);
		wrefresh(topwin);
		key = getch();
		pthread_mutex_unlock(&ncurses);
		if (key != ERR) {
			break;
		}
	}
	return NULL;
}

void * countDown(void *ptr) {
	int i = 0, key;

	while (1) {
		pthread_mutex_lock(&ncurses);
		wprintw(botwin, "Count down: %d\n", i--);
		wrefresh(botwin);
		key = getch();
		pthread_mutex_unlock(&ncurses);
		if (key != ERR) {
			break;
		}
	}
	return NULL;
}

int main(int argc, char **argv) {

	int tlines, blines;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	tlines = LINES/2-1;
	blines = LINES-tlines-1;
	
	topwin = newwin(tlines, COLS, 0, 0);
	scrollok(topwin, TRUE);
	botwin = newwin(blines, COLS, tlines+1, 0);
	scrollok(botwin, TRUE);
	move(tlines, 0);
	if (has_colors()) {
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_BLUE, COLOR_BLACK);
		wattron(topwin, COLOR_PAIR(1));
		wattron(botwin, COLOR_PAIR(2));
		wattron(stdscr, COLOR_PAIR(3));
	}
	hline('_', 200);
	refresh();
	
	if(pthread_mutex_init(&ncurses, NULL) != 0) {
		return 1;
	}

	// Thread code goes HERE!
	int i = 0;

	while(i<2) {
		if(i==0)
			pthread_create(&(tid[i]), NULL, &countUp, NULL);
		else if(i==1)
			pthread_create(&(tid[i]), NULL, &countDown, NULL);
		
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	usleep(3000000);
	endwin();	

	return 0;
}

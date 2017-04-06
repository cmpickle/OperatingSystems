#include <stdio.h>
#include <stdlib.h>

void position(int value, int *valuePos, int *array, int len) {
	int temp;
	int i;
	for(i=0; i<len; ++i) {
		if(*array == value) {
			temp = *array;
			*array = *valuePos;
			*valuePos = temp;
		}
		++array;
	}
}

int shortestDist(int src, int *dst, int len) {
	int min = abs(src-*dst);
	int minVal = *dst;
	++dst;
	int i;
	for(i=0; i<len; ++i) {
		if(abs(src-*dst)<min) {
			min = abs(src-*dst);
			minVal = *dst;
		}
		++dst;
	}
	return minVal;
}

int nextScan(int src, int *dst, int len) {
	int next = (src <= *dst)? abs(*dst-src):abs(*dst+256-src);
	int nextVal = *dst;
	++dst;
	int i;
	for(i=0; i<len; ++i) {
		if(src <= *dst) {
			if(abs(*dst-src)<next) {
				next = abs(*dst-src);
				nextVal = *dst;
			}
		} else {
			if(abs(*dst+256-src)<next) {
				next = abs(*dst+256-src);
				nextVal = *dst;
			}
			
		}
		++dst;
	}
	return nextVal;
}

int nextCScan(int src, int *dst, int len) {
	int next = (src <= *dst)? abs(*dst-src):abs(512-*dst-src);
	int nextVal = *dst;
	++dst;
	int i;
	for(i=0; i<len; ++i) {
		if(src <= *dst) {
			if(abs(*dst-src)<next) {
				next = abs(*dst-src);
				nextVal = *dst;
			}
		} else {
			if(abs((512-*dst)-src)<next) {
				next = abs((512-*dst)-src);
				nextVal = *dst;
			}
			
		}
		++dst;
	}
	return nextVal;
}

int removeElement(int *list, int element, int length) {
	int past = 0;
	int i;
	for(i=0; i<length-1; ++i) {
		if(*list == element) {
			continue;
			past = 1;
		}
		if(past)
			*list = *(list+1);
	}
	return length-1;
}

int main(int argc, char **argv) {
	if(argc != 10)
		exit(1);
	
	int *tracks = malloc(sizeof(int) * 9);
	int *tracks_head = tracks;
	//int *tracks_cpy = malloc(sizeof(int) * 9);
	//int *tracks_cpy_head = tracks_cpy;
	int *dist = malloc(sizeof(int) * 8);
	int *dist_head = dist;
	int total = 0;
	
	++argv;

	//Read in command line args to int *tracks
	while(*argv) {
		*tracks = atoi(*argv);
		++argv;
		++tracks;
	}
	tracks = tracks_head;
	
	//FCFS
	int count = 0;
	while(*tracks) {
		if(count<8)
			*dist = abs(*tracks - *(tracks+1));
		++tracks;
		++dist;
		++count;
	}
	tracks = tracks_head;
	dist = dist_head;

	printf("FCFS: Start:%d ", *tracks);
	++tracks;
	while(*tracks) {
		printf("%d:%d ", *tracks, *dist);
		++tracks;
		++dist;
	}
	tracks = tracks_head;
	dist = dist_head;

	int i;
	for(i=0; i<8; ++i) {
		total += *dist;
		++dist;
	}
	dist = dist_head;
	printf("Total:%d\n", total);
	total = 0;

	//SSTF
	int *current = tracks;
	++current;
	for(i=0; i<8; ++i) {
		int next = shortestDist(*(current-1), current, 8-i);
		position(next, current, current, 8-i);
		++current;
	}
	tracks = tracks_head;
	dist = dist_head;
	count = 0;
	while(*tracks) {
		if(count<8)
			*dist = abs(*tracks - *(tracks+1));
		++tracks;
		++dist;
		++count;
	}
	tracks = tracks_head;
	dist = dist_head;

	printf("SSTF: Start:%d ", *tracks);
	++tracks;
	while(*tracks) {
		printf("%d:%d ", *tracks, *dist);
		++tracks;
		++dist;
	}
	tracks = tracks_head;
	dist = dist_head;

	for(i=0; i<8; ++i) {
		total += *dist;
		++dist;
	}
	dist = dist_head;
	printf("Total:%d\n", total);
	total = 0;

	//SCAN
	current = tracks;
	++current;
	for(i=0; i<8; ++i) {
		int next = nextScan(*(current-1), current, 8-i);
		position(next, current, current, 8-i);
		++current;
	}
	tracks = tracks_head;
	dist = dist_head;
	count = 0;
	while(*tracks) {
		if(count<8)
			*dist = abs(*tracks - *(tracks+1));
		++tracks;
		++dist;
		++count;
	}
	tracks = tracks_head;
	dist = dist_head;

	printf("SCAN: Start:%d ", *tracks);
	++tracks;
	while(*tracks) {
		printf("%d:%d ", *tracks, *dist);
		++tracks;
		++dist;
	}
	tracks = tracks_head;
	dist = dist_head;

	for(i=0; i<8; ++i) {
		total += *dist;
		++dist;
	}
	dist = dist_head;
	printf("Total:%d\n", total);
	total = 0;

	//C_SCAN
	current = tracks;
	++current;
	for(i=0; i<8; ++i) {
		int next = nextCScan(*(current-1), current, 8-i);
		position(next, current, current, 8-i);
		++current;
	}
	tracks = tracks_head;
	dist = dist_head;
	for(i=0;i<8;++i) {
		*dist = abs(*tracks - *(tracks+1));
		++tracks;
		++dist;
	}
	tracks = tracks_head;
	dist = dist_head;

	printf("C_SCAN: Start:%d ", *tracks);
	++tracks;
	for(i=0;i<8;++i) {
		printf("%d:%d ", *tracks, *dist);
		++tracks;
		++dist;
	}
	tracks = tracks_head;
	dist = dist_head;

	for(i=0; i<8; ++i) {
		total += *dist;
		++dist;
	}
	dist = dist_head;
	printf("Total:%d\n", total);
	total = 0;

	return 0;
}

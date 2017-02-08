/*
 * Cameron Pickle
 * CS3100 - lab1
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


// usage() prints a standard usage statement
void usage(char *path) {
    fprintf(stderr, "Usage: %s -n NAME\n", path);
}

int main(int argc, char *argv[])
{
	char *name;

	if (argc != 3)
	{
		usage(argv[0]);
		exit(1);
	}
	
	// read the input parameter and exit on error
	int c;
	opterr = 0;
	while ((c = getopt(argc, argv, "n:")) != -1) 
	{
		switch (c) 
		{
			case 'n':
				name = optarg;
				break;
			default:
				usage(argv[0]);
				exit(1);
		}
	}
	
	// output on STDOUT "Welcome to Lab 1, written by USERNAME"
	printf("Welcome to Lab 1, written by %s\n", name);

	// output on STDOUT "Hostname: <hostname>"
	char hostname[15] = "";
	gethostname(hostname, sizeof hostname);
	printf("Hostname: %s\n", hostname);

	// output on STDOUT "PID and PPID: nnnnn/nnnnn"
	printf("PID and PPID: %5d/%5d\n", getpid(), getppid());

	// output on STDOUT "Program: <pathToThisProgram>"
	printf("Program: %s\n", argv[0]);
	
	return 0;
}


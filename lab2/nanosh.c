/* 
 *CS 3100 Lab 2 - by Cameron Pickle
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void cmdExit(int argc, char **argv) {
	if(argc > 1) {
		errno = EINVAL;
		perror("Exit command failed: ");
		return;
	}
	exit(0);
}

void pwd(int argc, char **argv) {
	if(argc == 1) {
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) == NULL) {
			perror("");
		}
		printf("%s\n", cwd);
		return;
	}
	errno = EINVAL;
	perror("Invalid number of parameters to pwd: ");
	return;
}

void cd(int argc, char **argv) {
	if(argc == 1) {
		//change working directory to $HOME
		chdir(getenv("HOME"));
		return;
	} else if(argc == 2) {
		//change working directyory to path specified in the agrument
		if(chdir(argv[1]) == -1) {
			perror("");
		}
		return;
	}
	errno = EINVAL;
	perror("Invalid number of parameters to cd: ");
	return;
}

// getParameters returns the argc, the number of words found in cmd
//  while populating argv with pointers to each word
int getParameters(char *cmd, char **argv) {
	char *token;
	int argc = 0;
	token = strtok(cmd, " \t\n");
	while (token != NULL) {
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;		// set last + 1 argument to NULL
	return argc;
}

int main(int argc, char **argv) {

	char cmd[1024];
	char *rc;
	int myArgc = 0;
	char *myArgv[1000];

	while (1) {
		printf("nanosh: ");
		fflush(stdout);
		rc = fgets(cmd, sizeof(cmd), stdin);
		//This shouldn't happen
		if (rc == NULL) {
			exit(0);
		}
		myArgc = getParameters(cmd, myArgv);

		// if no words typed: restart loop
		if (myArgc == 0) {			
			continue;
		}

		// if the first word is "exit", terminate the program
		if (strcmp(myArgv[0], "exit") == 0) {
			cmdExit(myArgc, myArgv);
			continue;
		}

		// add if statements here for the other internal commands
		if(strcmp(myArgv[0], "pwd") == 0) {
			pwd(myArgc, myArgv);
			continue;
		}

		if(strcmp(myArgv[0], "cd") ==0) {
			cd(myArgc, myArgv);
			continue;
		}

		//   and a default action that calls a function to fork()
		int proc = fork();
		//   and exec() while the parent issues waitpid()
		if(proc < 0) { //fork has failed
			perror("Fork failed: ");
			continue;
		} else if(proc == 0) { //child process ie the external command to be run
			if(execvp(cmd, myArgv)<0) {
				perror("");
				exit(1);
			}
			exit(0);
		} else { //parent process ie nanosh
			int status;
			if(waitpid(proc, &status, WUNTRACED | WCONTINUED)<0) {
				perror("");
			}	
			continue;
		}
	}

	return 0;
} 

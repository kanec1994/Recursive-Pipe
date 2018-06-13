#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void pipeline(int argNum, char* input[]);

int main(int argc, char* argv[]){
	pipeline(argc, argv);
	return(0);	
}

void pipeline(int argNum, char* input[]){
	pid_t pid;
	int status;
	int pfds[2];
	
	if(argNum != 1){
		if(pipe(pfds) == -1){
			perror("Pipe failed!\n");
			exit(1);	
		}
	
		if((pid = fork()) <= 0){
			perror("Fork failed!\n");
			exit(1);
		}
	
		if(pid == 0){
			close(0);
			if(dup2(pfds[0], 0) == -1){
				perror("stdin redirect failed!\n");
				exit(1);
			}
			close(pfds[1]);
			pipeline(argNum-1, newInput);	
		}
		else{
			close(1);
			if(dup2(pfds[1], 1) == -1){
				perror("stdout redirect failed!\n");
				exit(1);
			}
			close(pfds[0]);
		}
	}
	
		
}

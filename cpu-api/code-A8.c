#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int
main(int argc, char **argv){
	int pipe_fd[2];
	if(pipe(pipe_fd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	
	}

	pid_t rc1 = fork();
	
	if(rc1 < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
      	if (rc1 == 0) {
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execlp("ls", "ls", (char *)NULL);
		fflush(stdout);
		perror("execlp");
		exit(EXIT_FAILURE);
	}

	pid_t rc2 = fork();
	
	if(rc2 < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} 
	if (rc2 == 0) {
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		execlp("wc", "wc", "-l", (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	} 
       	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	
	waitpid(rc1, NULL, 0);
	waitpid(rc2, NULL, 0);
	
	return 0;
}

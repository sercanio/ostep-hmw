#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char **argv){
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello on child (pid: %d) \n", (int) getpid());
	} else {
		usleep(300); // sleep the parent for process 0.3 seconds 
		printf("goodbye on parent (pid: %d) \n", (int) getpid());
	}

	return 0;
}

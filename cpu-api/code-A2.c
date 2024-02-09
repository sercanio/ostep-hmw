#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char **argv){
	int fd = open("./A2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("On child (pid: %d) \n", (int) getpid());
		dprintf(fd, "Child process content.\n");
		close(fd);
	} else {
		wait(NULL);
		dprintf(fd, "Parent process content.\n");
		printf("On parent (pid: %d) \n", (int) getpid());
		close(fd);
	}

	return 0;
}

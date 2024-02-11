#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int
main(int argc, char **argv){
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("On child (pid: %d) \n", (int) getpid());

	} else {
		int status;
		pid_t wcpid = waitpid(rc, &status, 0);
		printf("wcpid = %d, exit status : %d\n", wcpid, WEXITSTATUS(status));
		printf("On parent (pid: %d) \n", (int) getpid());
	}

	return 0;
}

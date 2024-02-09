#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv){
	int x = 100;
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		x = 101;
		printf("x = %d on child (pid: %d) \n", x, (int) getpid());
	} else {
		int wc = wait(NULL);
		printf("x = %d on parent (pid: %d) \n", x, (int) getpid());
	}

	return 0;
}

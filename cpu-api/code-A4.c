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
		// execvp 
		// suffix v : require vector of arguments
		// suffix p : use PATH environment variable to find program
		//
		// char *myargs[3];
		// myargs[0] = strdup("ls");
		// myargs[1] = strdup("-l");
		// myargs[2] = NULL;
		// execvp(myargs[0], myargs);
		
		// execl 
		// suffix l : require list of arguments
		// without suffix p : we have to specify full path of the program
		// char *myargs[3];
		// myargs[0] = strdup("/bin/ls");
		// myargs[1] = strdup("ls");
		// myargs[2] = strdup("-l");
		// myargs[3] = NULL;
		// execl(myargs[0], myargs[1], myargs[2], myargs[3]);

		// execle
		// suffix e : require environment variable
		//
		char *myargs[4];
		char *envp[] = {"LS_COLORS=di=31:ln=32:so=33:pi=34:ex=35:bd=36:cd=37:or=91:mi=92:su=93:sg=94:ca=95:tw=96", NULL};
		myargs[0] = strdup("/bin/ls");
		myargs[1] = strdup("ls");
		myargs[2] = strdup("-l");
		myargs[3] = NULL;
		execle(myargs[0], myargs[1], myargs[2], myargs[3], NULL, envp);

	} else {
		wait(NULL);
		printf("On parent (pid: %d) \n", (int) getpid());
	}

	return 0;
}

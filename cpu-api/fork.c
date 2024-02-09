#include <stdio.h>

int
main(int argc, char **argv){
	int x = 100;
	int rc = fork();
	printf("Before changing x : pid:%d, x:%d \n", rc, x);
	x = 101;
	printf("After changing x : pid:%d, x:%d \n", rc, x);
      	return 0;
}

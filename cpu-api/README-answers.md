# Homework Answers

## A1
Action: a forks b
Tree :

	a
	|__ b

Action: a forks c
Tree: 

	a
 	|__ b
  	|__ c

Action: c EXITS
Tree: 

	a
	|__ b
	
Action: a forks d
Tree:

	a
	|__ b
	|__ d

Action: a forks e
Tree:

	a
	|__ b
	|__ d
	|__ e


## A2
For simplicity I used value of 5 for -a: 
```bash
./fork.py -a 5
```
When I use a larger value of -a the procecess trees getting incredibly complex.

Action: a forks c
Tree:

	a
	|__ c

Action: c forks d
Tree:

	a
	|__ c
	    |__d

Action: d EXITS
Tree:

	a
	|__ c

Action: a forks e
Tre: 

	a
	|__ c
	|__ e

## A3

Action: a forks b

Action: b forks c

Action: c EXITS

Action: a forks d

Action: d forks e

## A4

After c EXITS, processes d and e become orphaned processes and they become children of the root process. In this case process trees should like this:

Action: a forks b (a+b)
Tree:

	a
	|__ b

Action: b forks c (b+c)
Tree:

	a
	|__ b
	    |__ c

Action: c forks d (c+d)
Tree:

	a
	|__ b
   	    |__ c
		|__ d

Action: c EXITS (c-)
Tree:

	a
	|__ b
	|__ d
	|__ e

**With -R flag** orphaned processes wont be children of the root process, instead, they will be children of the parent process:

Action: c EXITS (c- -R)
Tree:
	
	a
	|__ b
	    |__ d
	    |__ e

## A5

Action: a forks b
Tree:

	a
	|__ b

Action: b EXITS
Tree:

	a

Action: a forks c
Tree:

	a
	|__ c

Action: c forks d
Tree:
	
	a
	|__ c
	    |__ d

Actions: c forks e
Tree:

	a
	|__ c
	    |__ d
            |__ e

## A6

Fimal Process Tree:

	a
	|__ d

Action: a forks b
Tree:
 
	a
	|__ b

Action: b EXITS:
Tree:

	a

Action: a forks c
Tree:

	a
	|__ c

Action: c forks d
Tree:

	a
	|__ c
	    |__ d

Action: c EXITS
Tree:

	a
	|__ d

# Code Homework
My answers for code workshop

## A1 
Initializing a variable before the fork() system call and then changing it's value inside the child process does not affect the parent process. See code-A1.c .

## A2
Both child and parent processes can manipulate opened file before the fork() system call. see code-A2.c that creates a file named A2.txt and it's written by both parent and the child processes.

## A3
We can wait the child process complete it's job without wait() system call. Simply we can use usleep(MILISECONDS) system call to "wait" for child process for such a time we specified. See code-A3.c

## A4
the word "exec" have suffix like **l**, **v**, **e**, **p**

- l : stands for "list" we should provide list of arguments,
- v : stands for "vector" we should provide an argument vector,
- e : stands for "environment" we should provide a custom environment variables
- p : stands for "path" we don't need to specify full path of the program it will yse the system variables to find that progra

see code-A4.c

## A5
wait() returns the pid of the child process. If wait() be used in the child processes it returns "-1" if there is no child under the child process :

```
wc: -1
On child (pid: 1292) 
wc: 1292
On parent (pid: 1290) 
```

See code-A5.c

## A6
waitpid() is more flexible alternative to the wait(). 
```
id_t wcpid = waitpid(rc, &status, 0);
printf("wcpid = %d, exit status : %d\n", wcpid, WEXITSTATUS(status));
```

we can print out with exit status of the child process that waitpid provide us.

For more details:
```
man waitpid
```

And also see code-A6.c

## A7
If we close standard output in child process with
```
close(STDOUT_FILENO);
```
the child can not print anymore, parent still can. 


/* USING FORK
** creates child processes from parent process 
** one at a time by
** waiting for child process to terminate
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv){
	char *read_process = (char*)malloc(sizeof(char) *100);
	
	printf("Enter number of child:");
	scanf("%s",read_process);
	
	int n_process = atoi(read_process);
	if(n_process < 1 | n_process > 20){
		puts("Error! max:20\n");
		fflush(stdout);
		exit(0);
	}
	pid_t child_pid[n_process];
	pid_t child_wstatus;
	for(int i = 0; i < n_process; i++){
		child_pid[i] = fork();
		switch(child_pid[i]){
			case -1:
				printf("Child %d NOT created!\n",i);
				break;
			case 0:
				printf("Hello from Child %d!\n",i);
				exit(0);
			default:
				printf("\nChild %d created with pid: %d !\n",i, child_pid[i]);
				waitpid(child_pid[i],&child_wstatus,0);
				if(WIFEXITED(child_wstatus)){
					printf("Child %d exited succesfully !\n",i);
				}
				else{
					printf("Child %d failed to exit !\n",i);
				}
				break;
		}
		
	}
	
	free(read_process);	
	return 0;
}
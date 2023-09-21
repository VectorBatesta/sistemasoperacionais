#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

int main(){
	int pid = fork();
	int status;
	
	char string[50];

	if (pid == 0){
		
		wait(&status);
		
		exit(5);
	}	
	else{
		scanf("%s", string);
	
		if (strcmp(string, "lista") == 0){ 
			execl ("/bin/ls", "ls", "-1", NULL);
		}
		
		if (strcmp(string, "processos") == 0){ 
			execl ("/bin/ps", "-a", "-1", NULL);
		}
		
		if (strcmp(string, "diretorio") == 0){ 
			printf("envie o diretorio: ");
			scanf("%s", string);
			execl ("/bin/cd", "cd", "-c", string, NULL);
		}
	}
	
	return 0;
}

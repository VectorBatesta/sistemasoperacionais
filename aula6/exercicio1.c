#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    int status;
    int pid = fork();
    
    if (pid > 1){
        wait(&status);
        pid = fork();
        printf("eu so o processo numero 0, pai de todos\n");
    }
    else if (pid > 0){
        wait(&status);
        pid = fork();
        printf("eu so o processo numero 1, filho de 0\n");
    }
    else if (pid == 0){
        printf("eu so o processo numero 2, filho de 1\n");
    }
    else {
        printf("erro carai");
    }

    return 0;
}

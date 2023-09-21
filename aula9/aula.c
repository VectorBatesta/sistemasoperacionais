#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

int main(){
    int PP[2];
    pipe(PP);
    int pid = fork();
    char buf[1024];

    if (pid == 0){
        write(PP[1], "olá \n", 6);
    }else{
        read(PP[0], buf, 1024);
        printf("msg recebida do filho %s", buf);
    }

    return(EXIT_SUCCESS);
}
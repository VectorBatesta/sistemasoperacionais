#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char *msg = "ola\n";

int ctrlZ;

//control z 3 vez fecha programa
void handlerTSTP(int signum){
	ctrlZ++;
	
	
	//bagulho do ascii
	int aux = ctrlZ + '0';
	
	write(1, "\nmano seloco, cê aperto esse carai ", 36);
	write(1, &aux, 1);
	write(1, " VEZES!!\n", 9);
	
	
	if(ctrlZ >= 3){
		exit(0);
	}
}


//alarmy
void handlerAL(int signum){
    write(1, "Sinal de alarme recebido\n", 25);
}


void handlerINT(int signum){
	write(1, msg, 5);
}



int main(){
    signal(SIGALRM, handlerAL);
    signal(SIGTSTP, handlerTSTP);
    signal(SIGINT, handlerINT);
    

    while(1){
        alarm(1);
        pause();
    }
    

    return 0;
}


















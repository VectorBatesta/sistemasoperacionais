#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


char* msgprintar;

void myprintf(int x, int y, char* msg){
	
	char stringespaco[14];

	//vem do 'mecher cursor' em https://en.wikipedia.org/wiki/ANSI_escape_code
	strcpy(stringespaco, "\033[48m\033[ B\033[ C");

	//escreve entre o [ e o B
	stringespaco[7]= x + '0';
	//escreve entre o [ e o C
	stringespaco[11]= y + '0';

	//printa no bash
	write(1, stringespaco, 14);
	write(1, msg, strlen(msg));
	write(1, "\n", 1);
}

void handlerALARME(int signum){
	
	write(1, msgprintar, strlen(msgprintar));	
	
}

void printsinc(char* msg, int segundos){

	msgprintar = malloc(strlen(msg) * (sizeof(char)));	

	//msgprintar <- msg
	strcpy(msgprintar, msg);

	//seta listener de alarme
	signal(SIGALRM, handlerALARME);		
	
	while(1){	
		alarm(segundos);
		pause();
	}

}


void main(){
	myprintf(4, 5, "Mensagem de teste");
	
	printsinc("olwá!\n",3);
}


#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//Um procedimento para contar o número de vezes que o usuário enviou o sinal SIGINT para o processo em execução. Pressionar Ctl-C no teclado envia esse sinal.
//Quando o processo recebe o sinal SIGTSTP (Ctl-Z), ele deve imprimir no terminal o número de sinais SIGINT que recebeu.
//Depois de receber 3 sinais SIGINT, o programa deve perguntar se o usuário deseja sair do programa. Se o usuário não responder em 20 segundos, um sinal SIGALRM deve forçar a saída do programa.

//write(1, msg, strlen(msg));

//signal(SIGALRM, handler);

int ctrlcCount;
char stringAviso[100];

void printer(char *stringNovo){
	strcpy(stringAviso, stringNovo);
	write(1, stringAviso, sizeof(stringAviso));
	strcpy(stringAviso, " ");
}


void handlerAlarmy(){
	strcpy(stringAviso, "\n\nVoce demorou demais!\n[Saindo do programa...]\n");
	
	write(1, stringAviso, sizeof(stringAviso));
	exit(0);
}

void handlerCTRLC(){
	ctrlcCount++;
	
	if(ctrlcCount >= 3){
		ctrlcCount = 0;
		printer("\nVoce gostaria de sair? [Y/N]\nResposta: ");
		alarm(3);
		
		char resposta, antibuffer;
		read(0, &resposta, 1);
		read(0, &antibuffer, 1);
		
		if (resposta == 'y'){
			exit(0);
		}
		else if (resposta == 'n'){
			alarm(0);
			printer("\nContinuando entao...\n\n");
		}
		else {
			printer("\nResposta indefinida!\n");
		}
	}
}

void handlerCTRLZ(){
	char aux[50];
	
	strcpy(aux, " CTRL-C apertado   vezes!!\n");
	aux[17] = '0' + ctrlcCount;
	
	printer(aux);
}


void main(){
	signal(SIGINT, handlerCTRLC);
	signal(SIGALRM, handlerAlarmy);
	signal(SIGTSTP, handlerCTRLZ);
	
	while(1);
}


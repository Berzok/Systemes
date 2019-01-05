#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



int main(void){

	
	pid_t leFils;
	time_t t;
	srand((unsigned) time(&t));
	int *nombre = (int *) malloc(sizeof(int));
	*nombre = (rand()%(1000-100)+100);
	int reponse[2];
	int echange_miracle[2];
	printf("Le nombre à trouver est: %d\n", *nombre);
	pipe(reponse);
	pipe(echange_miracle);
	leFils = fork();
	
	
	
	
	
	if(leFils == 0){		/* On est dans le processus fils */
		printf("Passage dans le processus fils\n");
		close(echange_miracle[0]);
		close(reponse[1]);
		int *answer = (int *) malloc(sizeof(int));
		int *essai = (int *) malloc(sizeof(int));
		int ecart[2] = {100, 1000};

		while(1==1){
		*essai = (rand()%(ecart[1]-ecart[0])+ecart[0]);
		
		printf("%d ====> \n", *essai);
		write(echange_miracle[1], essai, sizeof(*essai));
		
		read(reponse[0], answer, sizeof(*answer));
		fflush(stdout);
		printf("Réponse obtenue: %d\n", *answer);
		
		
		if(*answer == -1)
			ecart[1] = *essai;
		if(*answer == 1)
			ecart[0] = *essai;
		if(*answer == 0){
			printf("Fini.\n");
			break;
			}
		printf("ecart[0] = %d \n", ecart[0]);
		printf("ecart[1] = %d \n", ecart[1]);
		}
		}
	
	if(leFils != 0){		/* On est dans le processus père */
		close(echange_miracle[1]);
		close(reponse[0]);
		int *attempt = (int *) malloc(sizeof(int));
		int *INF = (int *) malloc(sizeof(int));
		*INF = -1;
		int *SUP = (int *) malloc(sizeof(int));
		*SUP = 1;
		while(1==1){
		read(echange_miracle[0], attempt, 44);
		printf("    ====> %d\n", *attempt);
		printf("INF: %d \nSUP: %d\n", *INF, *SUP);
		
		if(*attempt == *nombre){
			printf("Réussi\n");
			break;
			} 
	
		if(*attempt < *nombre){
			write(reponse[1], SUP, sizeof(*SUP));
			}
		if(*attempt > *nombre){
			write(reponse[1], INF, sizeof(*INF));
			}
		}
		}
	return EXIT_SUCCESS;
	}
	
	
	
	
	
	

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>




int main(void){

	
	pid_t leFils;
	int *nombre = malloc(sizeof(int));
	*nombre = (rand()%(1000-100)+100);
	leFils = fork();
	time_t t;
	srand((unsigned) time(&t));
	int echange_miracle[2];
	int reponse[2];
	
	int ecart[2] = {100, 1000};
	
	printf("Le nombre à trouver est: %d\n", *nombre);
	
	pipe(echange_miracle);
	pipe(reponse);
	
	
	
	while(1==1){
	if(leFils == 0){		/* On est dans le processus fils */
		printf("Passage dans le processus fils\n");
		close(echange_miracle[0]);
		close(reponse[1]);
		int *answer = NULL;
		int *essai = NULL;
		srand((unsigned) time(&t));
		*essai = (rand()%(ecart[1]-ecart[0])+ecart[0]);
		printf("On propose le nombre %d\n", *essai);
	
		write(echange_miracle[1], essai, sizeof(int));
		read(reponse[0], answer, sizeof(int));
		if(answer < 0)
			ecart[1] = *essai;
		else
			ecart[0] = *essai;
		}
	
	if(leFils != 0){		/* On est dans le processus père */
		printf("Passage dans le processus père\n");
		close(echange_miracle[1]);
		close(reponse[0]);
		int *attempt = malloc(sizeof(int));
		int *INF = malloc(sizeof(int));
		*INF = -1;
		int *SUP = malloc(sizeof(int));
		*SUP = 1;
	
		read(echange_miracle[0], attempt, 44);
	
		if(attempt == nombre){
			printf("Réussi\n");
			}
	
		if(attempt != nombre){
			if(attempt < nombre)
				write(reponse[1], INF, sizeof(int));
			else
				write(reponse[1], SUP, sizeof(int));
			}
		}
	
	}
	return EXIT_SUCCESS;
	}
	
	
	
	
	
	

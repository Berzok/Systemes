#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



int main(int argc, char *argv[]){

	int i=1;
	printf("[%d]\n", argc);
	char *commande = malloc(2 * argc * sizeof(char*));
	for(i=1; i<argc; i++){
		printf("[%d]: %s\n", i, argv[i]);
		strcat(commande, argv[i]);
		strcat(commande, " ");
		if((i%2==1 && i!=1 && i!=argc-1) || (i!=argc-1 && i!=1))
			strcat(commande, "| ");
		printf("\nLigne de commande: %s \n", commande);
		}
	printf("\nLigne de commande: %s \n", commande);
	system(commande);
	return 0;
	}
	
	
	


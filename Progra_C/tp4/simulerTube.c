#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


void simuler_tube_shell(char *cmd1, char *cmd2);


int main(void){

	
	char *cmd1 = malloc(42*sizeof(char));
	char *cmd2 = malloc(42*sizeof(char));
	
	printf("Première commande ?\n  ==>");
	fgets(cmd1, 99, stdin);
	
	
	printf("Deuxième commande ?\n  ==>");
	fgets(cmd2, 99, stdin);
	

	simuler_tube_shell(cmd1, cmd2);
	
	free(cmd1);
	free(cmd2);
	return 0;
	}
	
	
void simuler_tube_shell(char *cmd1, char *cmd2){
	
	int isLegal[2];
	pipe(isLegal);
	pid_t leFils=fork();
	
	if(leFils==0){
		close(isLegal[1]);
		int *check = (int *) (malloc(sizeof(int)));
		*check = 16;
			read(isLegal[0], check, sizeof(*check));

		system(cmd2);
		free(check);
		}
	else{
		close(isLegal[0]);
		system(cmd1);
		write(isLegal[1], (int *) 18, sizeof(int*));
		}
	
	
	return;
	}
	
	
	
	
	


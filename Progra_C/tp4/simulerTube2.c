#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

extern char **environ;


void simuler_tube_shell(char *cmd1, char *cmd2);
void rectifierCommande(char *commande);


int main(void){
	
	char *cmd1 = malloc(4*sizeof(char *));
	char *cmd2 = malloc(2*sizeof(char));
	
	printf("Première commande ?\n  ==>");
	fgets(cmd1, 99, stdin);
	//rectifierCommande(cmd1);
	
	printf("Deuxième commande ?\n  ==>");
	fgets(cmd2, 99, stdin);
	//rectifierCommande(cmd2);
	
	printf("[1]: %s \n", cmd1);
	
	
	
	
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
		close(isLegal[0]);
		execvp(cmd1, {"ls", "-a", NULL});
		write(isLegal[1], (int *) 18, sizeof(int*));
		}
	else{
		close(isLegal[1]);
		int *check = malloc(sizeof(int));
		*check = 16;
		printf("[1]: %s \n", cmd1);
		while(*check != 18)
			read(isLegal[0], check, sizeof(*check));
		execvp(cmd2, NULL);
		}
	
	
	return;
	}


void rectifierCommande(char *commande){
	
	char *cmd = malloc(2*sizeof(char *));
	strcat(cmd, "/bin/");
	strcat(cmd, commande);
	strcpy(commande, cmd);
	free(cmd);
	
	return;
	}
	
	
	
	


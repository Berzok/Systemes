#include <stdio.h>



int main(int argc, char *argv[]){
	
	printf("On va effectuer une redirection du déroulement du programme dans 'question2.txt' \n");
	
	freopen(argv[1], "a", stdout);
	
	printf("Texte à écrire dans le fichier");
	
	fclose(stdout);
	
	return 0;
	}

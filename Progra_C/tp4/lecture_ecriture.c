#include <stdio.h>
#include <stdlib.h>


void lire(char *nom, char *ajout);
void copier(char *nom, char *nom2);

int main(void){
	
	char *texteAjout = malloc(6*sizeof(char));
	printf("Texte à rajouter dans le fichier ?\n");
	scanf(" %s", texteAjout);
	
	
	char *leFichier = NULL;
	leFichier = "question3.txt";
	
	char *leFichier2 = NULL;
	leFichier2 = "question3bis.txt";
		
	
	lire(leFichier, texteAjout);
	
	copier(leFichier, leFichier2);
	
	
	return 0;
	}


void lire(char *nom, char *ajout){
	FILE *fichier = fopen(nom, "a+");
	char texte[30];
	fgets(texte, 99, fichier);
	printf("Dans le fichier, il est actuellement écrit:\n%s\n", texte);
	fputs(ajout, fichier);
	fclose(fichier);
}

void copier(char *nom, char *nom2){
	FILE *fichier1 = fopen(nom, "r");
	FILE *fichier2 = freopen(nom2, "w", stdout);
	char texte[30];
	while(fgets(texte, 99, fichier1) != NULL){
		puts(texte);
		puts("\n");
		}
	fclose(fichier1);
	fclose(fichier2);
	}
	

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



void lire(char *nom, char *ajout);
void copier(char *nom, char *nom2);

int main(void){
	
	char *texteAjout = malloc(6*sizeof(char));
	printf("Texte à rajouter dans le fichier ?\n");
	scanf(" %s", texteAjout);
	
	
	char *leFichier = NULL;
	leFichier = "question4.txt";
	
	char *leFichier2 = NULL;
	leFichier2 = "question4bis.txt";
		
	
	lire(leFichier, texteAjout);
	
	copier(leFichier, leFichier2);
	
	
	return 0;
	}


void lire(char *nom, char *ajout){
	int fichier = open(nom, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP);
	char texte[413];
	read(fichier, texte, 314);
	printf("Dans le fichier, il est actuellement écrit:\n%s\n", texte);
	write(fichier, ajout, strlen(ajout));
	write(fichier, "\n", 1);
	close(fichier);
}

void copier(char *nom, char *nom2){
	int fichier1 = open(nom, O_RDONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	int fichier2 = open(nom2, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	char texte[30];
	read(fichier1, texte, 413);
	write(fichier2, texte, 314);
	close(fichier1);
	close(fichier2);
	}
	

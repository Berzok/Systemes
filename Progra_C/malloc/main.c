#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonctions.h"

int main(void)
	{
	system("clear");
	int taille = definirTaille();
	printf("La taille sera donc de %d\n\n", taille);
	int* u[taille];
	
	//Remplir le tableau
	remplirTab(u, taille);
	
	afficherTab(u, taille);
	
	return 0;
	}




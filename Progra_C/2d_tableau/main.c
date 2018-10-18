#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonctions.h"

int main(void)
	{
	int lignes;
	int colonnes;
	system("clear");
	definirTaille(&lignes, &colonnes);
	
	printf("Le tableau aura donc %d lignes et %d colonnes\n\n", lignes, colonnes);
	int **tableau = NULL;
	
/*	int lesLignes = lignes;*/
/*	int lesColonnes = colonnes;*/
	
	//On alloue la mémoire
	allocationTab(tableau, lignes, colonnes);
	
	//Remplir le tableau
	remplirTab(tableau, lignes, colonnes);
	printf("... Tableau rempli.\n\n");
	
	
	//On affiche le tableau
	afficherTab(tableau, 5, 5);
	
	
	//On free le tableau
	free(tableau);
	
	
	
	return 0;
	}




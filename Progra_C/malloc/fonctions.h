#include <stdio.h>


int definirTaille();
int* allocationTab(int);
void remplirTab(int*, int);
void afficherTab(int*, int);
void FREEEEEEEEEDOOOM(int*);


int definirTaille()
	{
	int taille = 0;
	printf("Taille désirée du tableau ?\n");
	scanf(" %d", &taille);
	printf("\n\n");
	return taille;
	}


int* allocationTab(int taille)
	{
	int* tableau = NULL;
	tableau = (int*)malloc(taille * sizeof(int));
	return tableau;
	}


void remplirTab(int* tableau, int taille)
	{
	srand(time(NULL));
	int i = 0;
	for(i; i<=taille; i++)
		{
		tableau[i] = rand();
		}
	}
	
	
void afficherTab(int* tableau, int taille)
	{
	printf("Tableau:\n");
	int i = 0;
	for(i; i<taille; i++)
		{
		printf("*[%d]: ==> %d\n", &tableau[i], tableau[i]);
		}
	}
	
	
	
	
	
	
	
	
	
	
	

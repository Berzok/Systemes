	#include <stdio.h>


void definirTaille(int*, int*);
void allocationTab(int**, int, int);
void remplirTab(int* tableau[], int, int);
void afficherTab(int** tableau, int, int);
void FREEEEEEEEEDOOOM(int**, int, int);


void definirTaille(int* lignes, int* colonnes)
	{
	int lesLignes, lesColonnes;
	printf("Lignes du tableau ?\n");
	scanf(" %d", &lesLignes);
	*lignes = lesLignes;
	
	printf("\nColonnes du tableau ?\n");
	scanf(" %d", &lesColonnes);
	*colonnes = lesColonnes;
	printf("\n\n");
	return;
	}


void allocationTab(int** tableau, int lignes, int colonnes)
	{
	int i;
	
	*tableau = (int**)malloc(lignes * sizeof(int*));
	for(i=0; i<colonnes; i++)
		{
		tableau[i] = (int*)malloc(colonnes * sizeof(int));
		}
	return;
	}


void remplirTab(int** tableau, int lignes, int colonnes)
	{
	srand(time(NULL));
	int i = 0;
	int j = 0;
	tableau[i][j] = rand();
	for(i=0; i< 5; i++)
		{
		for(j=0; j<5; j++)
			{
			int value = rand();
			tableau[i][j] = value;
			}
		}
	return;
	}
	
	
void afficherTab(int** tableau, int lignes, int colonnes)
	{
	printf("Lignes = %d\n", lignes);
	printf("Tableau:\n");
	int i = 0;
	int j = 0;
	for(i=0; i <= 4; i++)
		{
		for(j=0; j<=4; j++)
			{
			printf("Tableau[%d][%d]: ==> %d\n", i, j, tableau[i][j]);
			}
		}
	}
	
	
	void FREEEEEEEEEDOOOM(int** tableau, int lignes, int colonnes)
		{
		int i = 0;
		for(i=0; i<lignes; i++)
			{
			free(tableau[i]);	
			}
		free(tableau);
		}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"
/*#include "memoire.c"*/
/*#include "memoire.h"*/
#include "gestion_clavier.c"
#include "gestion_clavier.h"


#define ESC 27
#define ENTER 10

int main()
	{
	system("clear");
	
	
	/**	AFFICHER LE MENU	**/
	afficherMenu(0);
	
	/*		SERPENT GENESIS		**/
	Snake *serpent = ovipare();
	grow(serpent);
	grow(serpent);
	grow(serpent);
	grow(serpent);
	lezarder(serpent);
	char tableau[15][15];
	int i = 0;
	int j;
	for(i=0; i<15; i++)
		{
		for(j=0; j<15; j++)
			{
			tableau[i][j] = "#";
			}
		}
	
	for(i=0; i<15; i++)
		{
		for(j=0; j<15; j++)
			{
			printf("%c", tableau[i][j]);
			}
		printf("\n");
		}
	
	return 0;
	}


int afficherMenu(int i)
	{
	system("clear");
	printf("\n\n");
	printf("   Bienvenue dans le jeu du Ssssserpent!\n\n");
	switch(i)
		{
		case 0:
			printf("  ->Commencer une nouvelle partie\n");
			printf("    Consulter les scores\n");
			printf("    Quitter\n\n");
			break;
		case 1:
			printf("    Commencer une nouvelle partie\n");
			printf("  ->Consulter les scores\n");
			printf("    Quitter\n\n");
			break;
		case 2:
			printf("    Commencer une nouvelle partie\n");
			printf("    Consulter les scores\n");
			printf("  ->Quitter\n\n");
			break;
		default:
			break;
		}
	char key;
	do
		{
		key = pressing_key();
		if(key == 'z')
			switch(i)
				{
				case 0:
					afficherMenu(2);
					break;
				default:
					afficherMenu(i-1);
					break;
				}
		if(key == 's')
			switch(i)
				{
				case 2:
					afficherMenu(0);
					break;
				default:
					afficherMenu(i+1);
					break;
				}
		if(key == ENTER)
			switch(i)
				{
				default:
					return i;
				case 2:
					exit(0);
				}
		}while(key != 'z' || key != 's' || key != ENTER);
	return 2;
	}
	
	
void lezarder(Snake *serpent)
	{
	Scale *courant = serpent->head;
	while(courant != NULL)
		{
		printf("[%d]  %s\n", courant->numero, courant->value);
		courant = courant->suivant;
		}
	return;
	}
	
void grow(Snake *serpent)
	{
	Scale *nouvelle = malloc(sizeof(*nouvelle));
	Scale *courant = serpent->head;
	while(courant->suivant != NULL)
		{
		courant = courant->suivant;
		}
	courant->suivant = nouvelle;
	nouvelle->precedent = courant;
	nouvelle->numero = courant->numero+1;
	strcpy(nouvelle->value, "o");
	nouvelle->suivant = NULL;
	return;
	}
	
	
Snake *ovipare()
	{
	Snake *serpent = malloc(sizeof(*serpent));
	Scale *ecaille = malloc(sizeof(*ecaille));
	ecaille->numero = 0;
	strcpy(ecaille->value, "@");
	ecaille->suivant = NULL;
	serpent->head = ecaille;
	return serpent;
	}
	

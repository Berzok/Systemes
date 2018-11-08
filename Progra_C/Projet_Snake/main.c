#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"
/*#include "memoire.c"*/
/*#include "memoire.h"*/
#include "gestion_clavier.c"
#include "gestion_clavier.h"


#define ESC 27

int main()
	{
	system("clear");
	
	afficherMenu(0);
	int lignes = getenv("LINES");
	printf("%d\n", lignes);
	
	char key;
	
	
	
	do{
		key = pressing_key();
		if(key == NO_KEY)
		{
			printf("Aucune touche\n");
		}
		else
		{
			printf("La touche %c a été appuyée...\n",key);
		}
		
	}while(key != ESC);

	printf("##\nle programme est terminé.\n");
	return 0;
	}


void afficherMenu(int i)
	{
	system("clear");
	printf("\n\n");
	printf("	Bienvenue dans le jeu du Ssssserpent!\n\n");
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
			printf("oui");
			break;
		}
	char key;
	do
		{
		key = pressing_key();
		switch(key)
			{
			case 'z':
				if(i==0)
					afficherMenu(2);
				else
					afficherMenu(i-1);
				break;
			case 's':
				if(i==2)
					afficherMenu(0);
				else
					afficherMenu(i+1);
			}
		}while(key != 'z' || key != 's');
	return;
	}
	
	
	

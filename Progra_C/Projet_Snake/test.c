#include <stdio.h>
#include "gestion_clavier.c"
#include "gestion_clavier.h"

int main()
{
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
		
	}while(key != 'esc');
	
	printf("##\nle programme est terminé.\n");
	return 0;
}

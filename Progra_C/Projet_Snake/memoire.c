#include <stdio.h>
#include <stdlib.h> //pour malloc et free
#include "memoire.h"



/**************************************/
/**      FONCTION PRINCIPALE         **/

int main(void)
{
    int dim1=0,dim2=0;
    int*  tab1D = NULL;
	int** tab2D = NULL;

    /* COMMENTER OU DECOMMENTER pour passer d'une version à l'autre*/

    /** PARTIE TABLEAU 1D**/
    /*//dim1 = recup_taille_v1();
    recup_taille_v2(&dim1);
 	//tab1D = alloc_1D_v1(dim1);
	alloc_1D_v2(&tab1D,dim1);

	saisir_tab1D(tab1D,dim1);
	afficher_tab1D(tab1D,dim1);

	desalloc_tab1D(tab1D);
*/
	/** PARTIE TABLEAU 2D**/
	recup_taille_2D(&dim1,&dim2);
	//tab2D = alloc_2D_v1(dim1,dim2);
	alloc_2D_v2(&tab2D,dim1,dim2);

	saisir_tab2D(tab2D,dim1,dim2);
	afficher_tab2D(tab2D,dim1,dim2);

	desalloc_tab2D(tab2D,dim1);

	return 0;
}

/**************************************/
/**     DEFINITIONS FONCTIONS RECUP  **/
unsigned int recup_taille_v1(void)
{
    int t=0;

    printf("Taille :");
    scanf(" %d",&t);

    return t;
}

/*  Il faut envoyer à la fonction l'adresse de la variable
    à modifier (même fonctionnement qu'avec un scanf), il faut
    donc utiliser dans la fonction un pointeur
*/
void recup_taille_v2(unsigned int* t)
{
    printf("Taille :");
    scanf(" %d",t);//pas besoin de "&", t est une adresse

    return;
}

/* Ici il y a deux valeurs de retours... Il ne peut donc y
    avoir qu'une seule version de la fonction en passant en
    entrée les deux variables (les dimensions) à saisir. Etant
    donné que l'on cherche à les modifier on doit envoyer des
    adresses lors de l'appel => on utilise donc des pointeurs
    dans la fonction.
*/
void recup_taille_2D(unsigned int* dim1,unsigned int* dim2)
{
    /*En utilisant la version recup v1*/
    /*
    printf("Recuperation de la Dimension 1 - ");
    *dim1 = recup_taille_v1();
    printf("Recuperation de la Dimension 2 - ");
    *dim2 = recup_taille_v1();
    */

    /*En utilisant la version recup v2*/
    printf("Recuperation de la Dimension 1 - ");
    recup_taille_v2(dim1); //surtout pas "*dim1"
    printf("Recuperation de la Dimension 2 - ");
    recup_taille_v2(dim2); //surtout pas "*dim2"

    return;
}

/**************************************/
/** DEFINITIONS FONCTIONS TABLEAU 1D **/

/*version 1 :   on renvoie directement le "tableau", c'est à dire
                c'est à dire l'adresse de la 1ère case du tableau.
*/
int* alloc_1D_v1(int dim)
{
	int * tab = NULL;
	int i=0;

	tab = (int*)malloc(dim*sizeof(int));

	return tab;
}

/*version 2 :   on va modifier directement le "tableau" dans la fonction appelante
                on envoie donc à la fonction l'adresse d'un int* => on manipule
                donc un int** dans la fonction
*/
void alloc_1D_v2(int** tab, int dim)
{
	*tab = (int*)malloc(dim*sizeof(int));

	return;
}

void saisir_tab1D(int* tab, int dim)
{
	int i=0,j=0;
	printf(" ** Saisir les coeffs du tableau 1D **\n");

	for(i=0;i<dim;i++)
	{
			printf("saisie de tab[%d] : ",i);
			scanf(" %d",&tab[i]);
	}
	return;
}

void afficher_tab1D(int* tab, int dim)
{
	int i=0,j=0;
	printf("\n**   AFFICHAGE TAB1D   **\n\t");

	for(i=0;i<dim;i++)
	{
			printf("%d ",tab[i]);
	}
	printf("\n** FIN AFFICHAGE TAB1D **\n\n");

	return;
}

/*  On cherche pas à modifier le "tableau du main" dans cette fonction
    mais juste à désallouer le tableau dynamique. On travaille donc
    avec une copie de l'adresse du tableau 1D. Inutile d'avoir une
    indirection comme avec la fonction d'allocation du tableau
    On envoie en argument à la fonction FREE la valeur que le malloc
    nous avait renvoyée.

*/
void desalloc_tab1D(int* tab)
{
	free(tab);

	return;
}

/**************************************/
/** DEFINITIONS FONCTIONS TABLEAU 2D **/

/*version 1 :   on renvoie directement le "tableau", c'est à dire
                c'est à dire l'adresse de la 1ère case du tableau.
*/
int** alloc_2D_v1(int dim1, int dim2)
{
	int ** tab = NULL;
	int i=0;

	tab = (int**)malloc(dim1*sizeof(int*));
	for(i=0;i<dim1;i++)
	{
		tab[i] = (int*)malloc(dim2*sizeof(int));
	}

	return tab;
}

/*version 2 :   on va modifier directement le "tableau" dans la fonction appelante
                on envoie donc à la fonction l'adresse d'un int** => on manipule
                donc un int*** dans la fonction
*/
void alloc_2D_v2(int*** tab, int dim1, int dim2)
{
	int i=0;

	*tab = (int**)malloc(dim1*sizeof(int*));
	for(i=0;i<dim1;i++)
	{
		(*tab)[i] = (int*)malloc(dim2*sizeof(int));
	}

	return;
}

void saisir_tab2D(int** tab, int dim1, int dim2)
{
	int i=0,j=0;
	printf(" ** Saisir les coeffs du tableau 2D**\n");

	for(i=0;i<dim1;i++)
	{
		for(j=0;j<dim2;j++)
		{
			printf("saisie du coeff <%d,%d> : ",i,j);
			scanf(" %d",&tab[i][j]);
		}
	}
	return;
}

void afficher_tab2D(int** tab, int dim1, int dim2)
{
	int i=0,j=0;
	printf("\n**   AFFICHAGE TAB2D   **\n");

	for(i=0;i<dim1;i++)
	{
		printf("\t");
		for(j=0;j<dim2;j++)
		{
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
	printf("** FIN AFFICHAGE TAB2D **\n\n");

	return;
}

/*  On cherche pas à modifier le "tableau du main" dans cette fonction
    mais juste à désallouer le tableau dynamique. On travaille donc
    avec une copie de l'adresse du tableau 2D. Inutile d'avoir une
    indirection comme avec la fonction d'allocation du tableau

*/
void desalloc_tab2D(int** tab,int dim1)
{
	int i=0;

	for(i=0;i<dim1;i++)
	{
		free(tab[i]);
	}
	free(tab);

	return;
}

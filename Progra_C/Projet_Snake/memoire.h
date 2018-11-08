#include <stdio.h>


typedef struct Mot_Myst
	{
	char** tableau;
	int nombreMots;
	} Mot_Myst;




/**************************************/
/**          PROTOTYPES              **/

unsigned int recup_taille_v1(void);
void recup_taille_v2(unsigned int* t);
void recup_taille_2D(unsigned int* dim1,unsigned int* dim2);

int* alloc_1D_v1(int dim);
void  alloc_1D_v2(int** tab, int dim);
void saisir_tab1D(int* tab, int dim);
void afficher_tab1D(int* tab, int dim);
void desalloc_tab1D(int* tab);

int** alloc_2D_v1(int dim1, int dim2);
void  alloc_2D_v2(int*** tab, int dim1, int dim2);
void saisir_tab2D(int** tab, int dim1, int dim2);
void afficher_tab2D(int** tab, int dim1, int dim2);
void desalloc_tab2D(int** tab,int dim1);

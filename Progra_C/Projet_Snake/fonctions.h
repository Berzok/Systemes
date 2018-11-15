#include <stdio.h>


#define ESC 27



/**************************************/
/**				STRUCTURES					**/


typedef struct Scale Scale;
struct Scale{
	int numero;
	Scale *suivant;
	Scale *precedent;
	char value[1];
	};

typedef struct{
	Scale *head;
	} Snake;


/**************************************/
/**       	   PROTOTYPES          		    **/

int afficherMenu(int);

Snake *ovipare();
void grow(Snake* snake);
void lezarder(Snake *serpent);

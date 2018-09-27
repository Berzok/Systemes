#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

/*void deltapos(int a, int b, int c);*/
/*void deltanul(int a, int b, int c);*/

int main(void)
	{
/*	char _char;*/
/*	int n;*/
/*	printf("Valeur de _char: ");*/
/*	scanf(" %c", &_char);*/
/*	printf("Valeur de n: ");*/
/*	scanf(" %d", &n);*/
/*	printf("\n");*/
/*	int char2 = (int)_char;*/
/*	printf("Valeur de char2: %d\n\n", char2);*/
/*	*/
/*	//numérique*/
/*	if( char2>='0' && char2<='9' ){*/
/*		printf("numérique\n");*/
/*		printf("%c \n", char2);*/
/*	}	*/
/*	//majuscule*/
/*	if( char2>='A' && char2<='Z'){*/
/*		if (n + char2 >'Z'){*/
/*			char2 += n - 26;*/
/*			printf("%c \n", char2);*/
/*		}*/
/*		else{*/
/*			char2 += n;*/
/*			printf("%c \n", char2);*/
/*		}*/
/*	}*/
/*	//minuscule*/
/*	if( char2>='a' && char2<='z'){*/
/*		if (n + char2>'z'){*/
/*			char2 += n - 26;*/
/*			printf("oui\n");*/
/*			printf("%c \n", char2);*/
/*		}*/
/*		else{*/
/*			char2 += n-26;*/
/*			printf("%c \n", char2);*/
/*		}*/
/*	}*/
/*	else{*/
/*		printf("erreur\n");*/
/*	}*/
	
	exercice4();
	
	return 0;
	}
	
void exercice4(void)
	{
	char earth_chan[25];
	printf("Veuillez s'il-vous-plaît entrer une chaîne de caractères\n");
	scanf(" %s\n", earth_chan);
	int segment;
	printf("Veuillez maintenant entrer une position à partir de laquelle charcuter le string\n");
	scanf(" %d\n", &segment);
	
	}
	
	
	
	
/*	int a;*/
/*	int b;*/
/*	int c;*/
/*	int delta;*/
/*	printf("exercice 5: \n");*/
/*	printf("Entrez valeurs de a, b et c pour ax²+bx+c \n");*/
/*	scanf(" %d", &a);*/
/*	scanf(" %d", &b);*/
/*	scanf(" %d", &c);*/
/*	delta = b * b - 4 * a * c;*/
/*	if (delta > 0)*/
/*		deltapos(a, b, c);*/
/*	else if (delta == 0)*/
/*		deltanul(a, b, c);*/
/*	else if (delta < 0)*/
/*		printf("Pas de résultat dans R");*/
/*	*/
/*	printf("Une autre équation ? y/autre char \n");*/
/*	char rep;*/
/*	scanf(" %c", &rep);*/
/*	if (rep =='y')*/
/*		main();*/
/*	else*/
/*		printf("orvoir");*/
/*	return 0;*/
/*	}*/
/*	*/
/*void deltapos(int a, int b, int c){*/
/*	int x1 =a+b+c;*/
/*	int x2 =a*(b+c);*/
/*	printf("x1 = %d et x2 = %d", x1, x2);*/
/*}*/
/*	*/
/*	*/
/*void deltanul(int a, int b, int c){*/
/*	int x = a+b+c;*/
/*	printf("x = %d", x);*/
/*}*/









	
/*	printf("exercice 9: \n");*/
/*	printf("Combien d'articles dans le tableau ?");*/
/*	int nb_article;*/
/*	float prixHT;*/
/*	scanf(" %d", &nb_article);*/
/*	printf("Combien coute l'article ?");*/
/*	scanf(" %f", &prixHT);*/
/*	*/
/*	printf("nombre d'articles : %2d \n", nb_article);*/
/*	*/
/*	printf("prix HT           : %5.2f \n", prixHT);*/
/*	*/
/*	float prix_TTC;*/
/*	prix_TTC = (prixHT + (prixHT*0.196))*nb_article;*/
/*	printf("prix TTC          : %5.2f \n", prix_TTC);*/
/*	*/







/*	printf("exercice 10 :\n")*/
/*	unsigned char u_char = 128;*/
/*	int _int = 256;*/
/*	int _int2 = 384;*/
/*	printf("u_char en uchar %d \n", u_char);*/
/*	printf("_int en int %d \n", _int);*/
/*	printf("_int2 en int %d \n", _int2);*/
/*	*/
/*	printf("u_char en int %d \n", (int)u_char);*/
/*	printf("u_char en char %d \n", (char)u_char);*/
/*	printf("_int en char %d \n", (char)_int);*/
/*	printf("_int en uchar %d \n", (unsigned char)_int);*/
/*	printf("_int2 en char %d \n", (char)_int2);*/
/*	printf("_int2 en uchar %d \n", (unsigned char)_int2);*/
	
	
/*	printf("Exercice 6")*/
/*	char _char;*/
/*	int _h;*/
/*	printf("Entrez un caractère :\n");*/
/*	scanf(" %c", &_char);*/
/*	printf("Entrez la hauteur de la pyramide :\n");*/
/*	scanf(" %d", &_h);*/
/*	int compteur;*/
/*	int i;*/
/*	int j;*/
/*	int k;*/
/*	for (compteur = 1 ; compteur <= _h ; compteur++){*/
/*		for(i = 0; i < (_h-compteur)/2+1; i++)*/
/*			printf(" ");*/
/*		for(j = 0; j<compteur; j++)*/
/*			printf("%c", _char);*/
/*		for(k=0; k<(_h-compteur)/2; k++)*/
/*			printf(" ");*/
/*		printf("\n");*/
/*	}*/	

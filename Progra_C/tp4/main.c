#include <stdio.h>
#include <stdlib.h>



int main(void){
	
	int i = fileno(stdin);
	int j = fileno(stdout);
	int k = fileno(stderr);
	printf("Input stream: %d \n", i);
	printf("Ouput stream:  %d \n", j);
	printf("Error stream: %d \n", k);
	
	return 0;
	}

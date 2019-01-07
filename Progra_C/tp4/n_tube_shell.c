#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



int main(int argc, char *argv[]){

	int i=1;
	
	for(i=1; i<=argc; i++){	
		system(argv[i]);
		fork();
		if(fork()==1){
			system(commande);
			continue;
			}
		else
			break;
		}
	return 0;
	}
	
	
	


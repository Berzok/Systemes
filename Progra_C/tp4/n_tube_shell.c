#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



int main(int argc, char *argv[]){

	
	int pesterchum[2];
	pipe(pesterchum);
	
	char *cmd = malloc(sizeof(char));
	
	
	int the_final_countdown = 0;
	write(pesterchum[1], argv[0], sizeof(argv[0]));
	
	while(the_final_countdown<argc){
		fork();
		if(fork()==1){
			read(pesterchum[0], cmd, sizeof(char));
			system(cmd);
			write(pesterchum[1], argv[the_final_countdown], sizeof(char));
			}
		if(fork()==0){
			read(pesterchum[0], cmd, sizeof(char));
			system(cmd);
			}
		the_final_countdown++;
		}
	
	
	
	
	free(cmd);


	return 0;
	}
	
	
	


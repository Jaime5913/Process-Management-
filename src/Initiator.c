#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char *argv[]){

pid_t pid;

if (argc != 2 ) {
 printf("Invalid number of arguments");
	return 1;
	}
//Opens the file given from the command line and uses the read mode to look at its contents.
FILE *fp; 

fp  = fopen(argv[1],"r");


char buff[256];
int statusSpecial;
int statusSequen;
//This while loop reads through the file given line by line and deals with the input in buff 
while(fgets(buff,sizeof(buff),fp)) {

	pid = fork();

	if(pid < 0){
		printf("Fork Failed");
		return 1;
	} 

	else if(pid == 0) {
		execlp("./SpecialNumbers","SpecialNumbers", buff, NULL);
			
	}

	else {
		printf("[Initiator] [%d]:Waiting for the child process %d\n",getpid(), pid );
			waitpid(pid, &statusSpecial, 0);
		printf("[Initiator] [%d]: :The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusSpecial));
	}

	pid = fork();

        if(pid < 0){
                printf("Fork Failed");
                return 1;
        }

        else if(pid == 0) {
                execlp("./SequentialNumbers","SequentialNumbers", buff, NULL);

        }

        else {
                printf("[Initiator] [%d]:Waiting for the child process %d\n",getpid(), pid );
                        waitpid(pid, &statusSequen, 0);
                printf("[Initiator] [%d]:The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusSequen));
        }

		printf("[Initiator][%d]:The SpecialNumbers child process returned %d\n ",getpid(), WEXITSTATUS(statusSpecial) );
		printf("[Initiator][%d]:The SequentialNumbers child process returned %d\n ",getpid(), WEXITSTATUS(statusSequen) );
}

fclose(fp); 

return 0;
}

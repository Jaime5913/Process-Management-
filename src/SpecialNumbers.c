#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
int statusPrime;
int statusSqr;
pid_t pid; 
pid = fork();

        if(pid < 0){
                printf( "Fork Failed");
                return 1;
        }

        else if(pid == 0) {
                execlp("./Prime","Prime", argv[1], NULL);

        }

        else {
                printf("[SpecialNumbers] [%d]:Waiting for the child process %d\n",getpid(), pid );
                        waitpid(pid, &statusPrime, 0);
                printf("[SpecialNumbers] [%d]: :The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusPrime));
        }

        pid = fork();

        if(pid < 0){
                printf("Fork Failed");
                return 1;
        }

        else if(pid == 0) {
                execlp("./Square","Square", argv[1], NULL);

        }

        else {
                printf("[SpecialNumbers] [%d]:Waiting for the child process %d\n",getpid(), pid );
                        waitpid(pid, &statusSqr, 0);
                printf("[SpecialNumbers] [%d]:The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusSqr));
        }

                printf("[SpecialNumbers][%d]:The prime  child process returned %d\n ",getpid(), WEXITSTATUS(statusPrime) );
                printf("[SpecialNumbers][%d]:The square  child process returned %d\n ",getpid(), WEXITSTATUS(statusSqr) );

return 0;
}


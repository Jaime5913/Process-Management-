#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char *argv[]){


int statusPer;
int statusPav;
pid_t pid;
 pid = fork();

        if(pid < 0){
                printf("Fork Failed");
                return 1;
        }

        else if(pid == 0) {
                execlp("./Padovan","Padovan", argv[1], NULL);

        }

        else {
                printf("[SequentialNumbers] [%d]:Waiting for the child process %d\n",getpid(), pid );
                        waitpid(pid, &statusPav, 0);
                printf("[SequentialNumbers] [%d]: :The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusPav));
        }

        pid = fork();

        if(pid < 0){
                printf("Fork Failed");
                return 1;
        }

        else if(pid == 0) {
                execlp("./Perrin","Perrin", argv[1], NULL);

        }

        else {
                printf("[SequentialNumbers] [%d]:Waiting for the child process %d\n",getpid(), pid );
                        waitpid(pid, &statusPer, 0);
                printf("[SequentialNumbers] [%d]:The child process %d returned %d\n", getpid(), pid, WEXITSTATUS(statusPer));
        }

                printf("[SequentialNumbers][%d]:The padovan  child process returned %d\n ",getpid(), WEXITSTATUS(statusPav) );
                printf("[SequentialNumbers][%d]:The perrin  child process returned %d\n ",getpid(), WEXITSTATUS(statusPer) );

return 0;
}

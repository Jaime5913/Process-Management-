#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

int sum = 0;

for (int i = 1; i < argv[1]; i++){
	
	sum += i + i;



}








printf("[Square][%d]:The sum of the first %d squares is %d\n", getpid(), argv[1], sum);

if(sum < 100){

        return sum;
}

        else{
                return 100;
}







}

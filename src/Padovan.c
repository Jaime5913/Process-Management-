#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

int xval = 0;
int yval = 0;
int zval = 1;
int wval = 1;

int sum = 0;


for(int i = 0; i <= argv[1]; i++ ){

	wval = xval + yval;
	xval = yval;
	yval = zval;
	zval = wval;

	sum += wval;

}


	printf("[Padovan][%d]:The sum of the first %d numbers of the Padovan sequence is %d\n", getpid(), argv[1], sum);

if(sum < 100){

        return sum;
}

        else{
                return 100;
}
}

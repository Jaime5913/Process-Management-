
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




int main(int argc, char *argv[]){

int xval = 3;
int zval = 0;
int yval = 2;
int wval = 0;
int sum = 5;



if(argv[1] == 0){

	sum = 0;
}

else if(argv[1] == 1){
	
	sum = 1;
}

else if(argv[1] == 2){

	sum = 3;
}


for (int i = 3; i < argv[1]; i++){

	wval = zval + xval;
	xval = zval;
	zval = yval;
	yval = wval;
	sum += wval;


}

	printf("[Perrin][%d]:The sum of the first %d numbers of the Perrin series is %d\n ", getpid(), argv[1], sum);

if(sum < 100){

        return sum;
}

        else{
                return 100;
}
}

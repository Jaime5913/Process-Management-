#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[]){

int totalSum = 0;

if(argv[1] == 0 || argv[1] == 1){
	return 0;
}


for(int n=2; n <= argv[1]; n++)
    {
        int prime = 1;
        for(int i=2; i < n; i++){
            if(n%i == 0)
            {
                prime = 0;
                break;
            }
	}
        if(prime){
	totalSum += n;
}
           
	
    }
	printf("[Prime][%d]:The sum of the prime numbers <= %d is %d\n ", getpid(), argv[1], totalSum);


	if(totalSum < 100){

	return totalSum;
}

	else{
		return 100;
}
    
    
}


#include <stdio.h>
#define NUM 7

int iteration(int num){
		int fact=1;
		for(int i=1; i<=num; i++){
				fact=fact*i;
		}
		return fact;
}

int recursion(int num){
		if(num==0) return 1;
		else return num*recursion(num-1);
}

int main(){
		printf("factorial of %d using iteration: %d\n", NUM, iteration(NUM));
		printf("factorial of %d using recusrion: %d\n", NUM, recursion(NUM));
}

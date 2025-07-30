#include <stdio.h>
#include <stdlib.h>

void main(){
		printf("Enter a number\n");
		int num;
		scanf("%d", &num);
		
		if (num%5==0) printf("Is divisible by 5\n");
		else printf("Not divisible by 5\n");
}

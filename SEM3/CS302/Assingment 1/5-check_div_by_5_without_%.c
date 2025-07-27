#include <stdio.h>
#include <stdlib.h>

int is_divisible_by_5(int num){
		num = abs(num);
		int last_digit=num;
		while(last_digit>=10){
				last_digit-=10;
		}
		if (last_digit==0||last_digit==5)return 1;
		else return 0;
}

void main(){
		int number;
		printf("Enter an integer: ");
		scanf("%d", &number);

		if(is_divisible_by_5(number)) printf("%d is divisible by 5\n", number);
		else printf("%d is not divisible by 5\n", number);
}

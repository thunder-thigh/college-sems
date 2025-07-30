#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int main(){

		//OLDER ATTEMPT
		/*
		int128_t binary_num;
		int64_t decimal_num=0;
		int64_t multiplier=1;

		printf("Enter a binary num\nSupported 63 characters: ");
		scanf("%"SCNd128, &binary_num);

		if(binary_num!=0) decimal_num=1;
		for(;binary_num!=0; binary_num/=10){
				decimal_num+=multiplier*(binary_num%10);
				multiplier*=2;
		}
		printf("Decimal: %"PRId64"\n", decimal_num);
		*/
		//OLDER ATTEMPT ENDS HERE
		

		//BETTER AND NEWER CODE
		uint64_t decimal_num=0;
		char c;
		short int count = 0;
		printf("Enter a binary num\nSupported 63 characters: ");
		while((c=getchar()) != '\n' && count <63) {
				if(c == '0' || c == '1'){
						decimal_num=(decimal_num<<1) | (c-'0');
						count++;
				}
				else {
						printf("Invalid character detected: '%c'\nPlease enter only valid chars (0s and 1s)\n",c);
						return 1;
						}
				}
		
		printf("Decimal value: %"PRIu64"\n", decimal_num);
}

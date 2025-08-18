#include <stdio.h>

#define SIZE 100

void main(){

		int array[SIZE];
		int size_of_array=-1;

		printf("Start entering elements\nSupported till 100 entries\nEnter a character to stop\n");

		for (int i=0; i<SIZE; i++){
				if(scanf("%d", &array[i])==1) size_of_array++;
				else {
						printf("Character entered, stopping entries\n");
						if (getchar()!='\n' && getchar ()!=EOF) break;
				}
		}

		int temp;
		printf("Enter a number to scan: ");
		scanf("%d", &temp);
		
		for (int i=0; i<size_of_array; i++){
				if(temp==array[i]) printf("Number found at position: %d\n", i);
		}
}

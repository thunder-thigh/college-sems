#include <stdio.h>

#define SIZE 20

int main(){
	int array[SIZE] = {7, 24, 13, 3, 91, 56, 8, 42, 19, 65, 2, 37, 78, 5, 10, 83, 29, 6, 48, 94};
	int temp;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<i; j++){
			if (array[i]<array[j]){
				temp = array[i];
				for (int k=i; k>j; k--){
					array[k]=array[k-1];
				}
				array[j]= temp;
				break;
			}
		}
	}
	printf("Array: \n");
	for (temp=0; temp<SIZE; temp++){
		printf("%d, ",array[temp]);
	}
	printf("\n");
}

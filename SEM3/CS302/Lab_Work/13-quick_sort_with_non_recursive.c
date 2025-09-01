#include <stdlib.h>
#include "aashu.h"

#define SIZE 30

void swap_old(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
}


void swap(int array[], int a, int b){
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
}

int partitionHoare(int array[], int low, int high){
		//Partition using Hoare's scheme from mid;
		int pivot = array[(high+low)/2];
		
		while(1){
				while (array[low]<pivot) low++;
				while (array[high]>pivot) high--; 
				if (low>=high) return high;
				//swap_old(&array[low], &array[high]);
				swap(array, low, high);
				low++;high--;
		}
		return high;
}

void quick_sort_array_without_recursion(int array[], int l, int r){
		int *stack = malloc(2*sizeof(int)*(r-l+1));
		//keep malloc function without the int* at starting, since explicit typecasting isredundant
		//this gives a void pointer which is easier to work with.
		// int *top = stack;
		int top = -1;
		stack[top++] = l;
		stack[top++] = r;
		while(top>=0){
				r = stack[top--];
				l = stack[top--];
		//	printf("l: %d, r: %d\n", l, r);
				int p = partitionHoare(array, l, r);
				if(l<p){
						stack[++top]=l;
						stack[++top]=p;
				}
				if(p+1<r){
						stack[top]=p+1;
						stack[top]=r;
				}
		}
		free(stack);
		//for (int i=0; i<SIZE; i++){
		//printf("%d, ", array[i]);
		//}
}

int main(){
		int array[SIZE] = {-25, 87, 12, -6, 91, 3, -48, 70, 19, -33, 55, 2, -18, 99, 41, -72, 63, 15, -90, 27, 8, -50, 77, 36, -11, 84, 22, -65, 49, -4};
		//int array[SIZE] = {-1,-11,0,14,5};
		quick_sort_array_without_recursion(array, 0, SIZE-1);
		for (int i=0; i<SIZE; i++){
				printf("%d, ", array[i]);
		}
		NEWLINE;
}

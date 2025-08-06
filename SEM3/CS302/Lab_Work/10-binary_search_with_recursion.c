//#include <stdlib.h>
#include <stdio.h>

#define SIZE 30
int binary_search(int *num, int *first, int *last, int *mid, int *array){
	if (*first > *last) return 0;
	if (*num == array[*mid]){
		printf("Number found at %d position\n", *mid);
		return 1;
//		exit(1);
	}
	else if (*num < array[*mid]){
		*last=*mid-1;
		*mid=(*first+*last)/2;
		binary_search(num, first, last, mid, array);
	}
	else {
		*first=*mid+1;
		*mid=(*first+*last)/2;
		binary_search(num, first, last, mid, array);
	}
}

	
void main(){

	int list[SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int num, first =0, last=SIZE-1, mid=(first+last)/2;

	printf("Enter num to search for: ");
	scanf("%d", &num);
	int *num_p=&num, *first_p=&first, *last_p=&last, *mid_p=&mid;
	if (binary_search(num_p, first_p, last_p, mid_p, list)==0)
		printf("Number could not be located within the list\n");
//	printf("Number could not be located within the list\n");
}

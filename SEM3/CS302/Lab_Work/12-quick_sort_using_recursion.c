#include"aashu.h"

#define SIZE 20
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Using my own partition scheme. [Does not work]
/* void quicksort(int array[], int low, int high){
	if (low>=high) return;
	int pivot_position = (low+high)/2;
	for (int i=low; i<=high; i++){
		if (array[i]>array[pivot_position] && i>pivot_position){
			//swap(&array[i], &array[pivot_position]);
			swap(&i, &pivot_position);
			pivot_position=i;
		}
		if (array[i]<array[pivot_position] && i<pivot_position){
			//swap(&array[i], &array[pivot_position]);
			swap(&i, &pivot_position);
			pivot_position=i;
		}
	}
	quicksort(array, low, pivot_position-1);
	quicksort(array, pivot_position+1, high);
}
*/
//Using hoare partition scheme
/* 1. Make two pointers i and j from start, end of array
 * 2. Choose a random pivot
 * 3. Increment i till an element greater than pivot is found
 * 4. Increment (move closer to pivot that is --1) j till a smaller than pivot element is found.
 * 5. swap i and j elements if i!>=j
 * 6. either j or i can be taken as pivot
*/

void quicksort(int array[], int start, int end){
	if (start>=end) return;
	int pivot_value = array[(start+end)/2];
	int left=start, right=end;
	while(left <= right){
		while (array[left]<pivot_value) left++;
		while (array[right]>pivot_value) right--;
		if (left<=right){
		swap(&array[left], &array[right]);
		left++;
		right--;
		}
	}
	quicksort (array, start, right);
	quicksort (array, left, end);
}

int main(){

	int array[SIZE]={7, 24, 13, 3, 91, 56, 8, 42, 19, 65, 2, 37, 78, 5, 10, 83, 29, 6, 48, 94};
	
	quicksort(array, 0, SIZE-1);
	printf("Sorted array is:\n");
	for (int i=0; i<SIZE; i++){
		printf("%d, ",array[i]);
	}
	NEWLINE
}

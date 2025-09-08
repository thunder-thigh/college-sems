#include <stdio.h>

#define SIZE 10
#define DE ;

/*
void swap(int *a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int array[], int weight[], int start, int end){
	if (start>=end) return;
	int pivot_value = array[(start+end)/2];
	int left=start, right=end;
	while(left <= right){
		while (array[left]<pivot_value) left++;
		while (array[right]>pivot_value) right--;
		if (left<=right){
		swap(&array[left], &array[right]);
		swap(&weight[left], &array[right]);
		left++;
		right--;
		}
	}
	quicksort (array, weight, start, right);
	quicksort (array, weight, left, end);
}
*/

void sort_array(float arr[], int values[], int weights[], int n){
	int i, j, temp, temp_weight;
	float ratio;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				// Swap
				ratio = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ratio;
				temp_weight = weights[j];
				weights[j] = weights[j + 1];
				weights[j + 1] = temp_weight;
				temp = arr[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

void calc_value_by_weight(int values[], int weights[], float val_to_weights[], int size){
	for (int i=0; i<size; i++){
		val_to_weights[i] = (values[i]*1.0)/(weights[i]*1.0);
	}
}

int main(){
	int values[SIZE] =  {12,14,16,77,34,16,46,42,81,21};
	int weights[SIZE] = {14,16,77,34,16,46,42,81,21,12};
	float val_to_weight[SIZE];
	calc_value_by_weight(values, weights, val_to_weight, SIZE);
	sort_array(val_to_weight, values, weights, SIZE);
DE	printf("values:\t");	
DE	for (int i=0; i<SIZE; i++){
DE		printf("%d, ", values[i]);
DE	}
DE	printf("\n");
DE	printf("weight:\t");	
DE	for (int i=0; i<SIZE; i++){
DE		printf("%d, ", weights[i]);
DE	}
DE	printf("\n");
DE	for (int i=0; i<SIZE; i++){
DE		printf("%f, ", val_to_weight[i]);
DE	}
DE	printf("\n");
//	perform_greedy_knapsack_problem(values, weights, val_to_weight);
}

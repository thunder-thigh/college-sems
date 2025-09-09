#include "aashu.h"

#define SIZE 10

int replace_array(int substitute_array[], int original_array[], int small_start, int small_end, int large_start, int large_end){
		for (int i=small_start; i<=small_end; i++){
				substitute_array[i] = original_array[i];
		}
		for (int i=large_start; i<=large_end; i++){
				substitute_array[i] = original_array[i];
		}
}

int merge_sort(int substitute_array[], int array[], int start, int end){
		if (start==end) return;
		merge_sort(substitute_array, array, start, (start+end)/2);
		merge_sort(substitute_array, array, (start+end)/2+1, end);
		if(array[(start+end)/2]>=array[(start+end)/2+1]) replace_array(substitute_array, array, start, (start+end)/2, (start+end)/2+1, end);
}

int main(){
		int array_unsorted[SIZE]={12,15,-1254,165,0,13,51,16,0,214};
		int array_sorted[SIZE];
		merge_sort(array_sorted, array_unsorted, 0, SIZE-1);
		for (int i=0; i<SIZE; i++){
				printf("%d, ", array_sorted[i]);
		}
		NEWLINE;
}


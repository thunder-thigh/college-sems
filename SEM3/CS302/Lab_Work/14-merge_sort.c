#include "aashu.h"

#define SIZE 10

int merge_sort(int array[], int start, int end){
		if (start==end) return;

		merge_sort(array, start, (start+end)/2);
		merge_sort(array, (start+end)/2, end);
}

int main(){
		int array_unsorted[SIZE]={12,15,-1254,165,0,13,51,16,0,214};
		int array_sorted[SIZE];
}


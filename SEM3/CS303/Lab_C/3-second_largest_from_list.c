//Print 2nd largest from a list of given numbers

#include <stdio.h>

void main(){
		int array[]={2,123,541,12,311231,1231,11232,541,-3,5};
		int max=array[0];
		int second_max=array[0];
		int size = sizeof(array)/sizeof(array[0]);

		for(int i=0;i<10;i++){
				if (array[i]>max){
						second_max = max;
						max = array[i];
				} else if (array[i]<max && array[i]>second_max) second_max = array[i];
		}
		printf("max = %d\nsecond max = %d\n", max, second_max);
}

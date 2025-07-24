//Print min and max from a list of given numbers

#include <stdio.h>

void main(){
		int array[10]={12,123,541,12,311231,1231,132,541,-3,5};
		int min=array[0];
		int max=array[0];

		for (int i=0;i<10;i++){
				if (array[i]>max) max = array[i];
				else if (array[i]<min) min = array[i];
		}
		printf("min = %d\nmax = %d\n", min, max);
}

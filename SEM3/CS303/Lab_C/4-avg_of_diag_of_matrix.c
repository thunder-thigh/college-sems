//Calculate average of the diagonal of a given square matrix

#include <stdio.h>

int main(){
		int array[5][5]={
				{123,1231,41,41,15},
				{15,616,16,-1231,0},
				{12,414,43,411,211},
				{12,15455,51,-15,2},
				{100,2,111,142,525}
		};
		int size = 5;
		float sum = 0;

		for (int i=0;i<size;i++){
				sum = sum+array[i][i];
		}
		printf("Average of diagonal elements in array: %f\n", sum/size);
}

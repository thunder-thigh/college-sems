#include <stdlib.h>
#include <stdio.h>

#define SIZE 30

void main(){

		int list[SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
		int first =0, last=SIZE-1, mid=(first+last)/2;
		int num;
		printf("Enter num to search for: ");
		scanf("%d", &num);

		while(first<=last){
				if(num==list[mid]){
						printf("%d found at index: %d\n",num, mid);
						exit(1);
				} else if(num<list[mid]) last=mid-1;
				else first=mid+1;
				mid = (first+last)/2;
		}
		printf("Number could not be located within the list\n");
}

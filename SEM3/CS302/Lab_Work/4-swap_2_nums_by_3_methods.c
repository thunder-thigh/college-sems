#include <stdio.h>

#define NUM1 12
#define NUM2 541

int temp_var(int a, int b){
		printf("a and b before swap: %d %d\n", a, b);
		int temp=a;
		a=b;
		b=temp;
		printf("a and b after swap: %d %d\n", a, b);
}

int xor(int a, int b){
		printf("a and b before swap: %d %d\n", a, b);
		a = a^b;
		b = a^b;
		a = a^b;
		printf("a and b after swap: %d %d\n", a, b);
}

int arithematic(int a, int b){
		printf("a and b before swap: %d %d\n", a, b);
		a = a+b;
		b = a-b;
		a = a-b;
		printf("a and b after swap: %d %d\n", a, b);
}

int main(){
		printf("Swap using temporary variable:\n");
		temp_var(NUM1, NUM2);
		printf("Swap using xor:\n");
		xor(NUM1, NUM2);
		printf("Swap using arithematic:\n");
		arithematic(NUM1, NUM2);
}

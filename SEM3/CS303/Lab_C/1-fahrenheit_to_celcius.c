//Program for fahrenheit -> celcius

#include <stdio.h>

void main(){
		float fahr;
		printf("Enter temperature in fahrenheit: ");
		scanf("%f", &fahr);
		printf("fahr: %f\ncelc: %f\n", fahr, (5.0/9.0)*(fahr-32));
}

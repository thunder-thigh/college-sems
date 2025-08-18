#include "aashu.h"

int reverse_string(){
		char temp;
		scanf("%c", &temp);
		if (temp == '\n')
				return 0;
		else reverse_string();
		printf("%c",temp);
}
		
int main(){
		printf("This program will reverse characters you enter\n");
		printf("Start entering your string: ");
		reverse_string();
		NEWLINE
}

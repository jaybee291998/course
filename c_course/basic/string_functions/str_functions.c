#include <stdio.h>
#include <string.h>

int main() {
	char string1[] = "Broly";
	char string2[] = "Collie";
	char string3[50];
	
	strcpy(string3, string2);
	
	printf("%s\n", string3);
	printf("%ld\n", strlen(string3));

	int arraySize = sizeof(string3);

	printf("size of array: %d", arraySize);

}

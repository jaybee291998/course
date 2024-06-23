#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* returnString(char *str);

int main() {
	char str[10] = "jayvee";
//	printf("str: %s\n", str);
	char *str2 = returnString(str);

	printf("str2: %s\n", str2);
}

char* returnString(char *str) {
//	char str2[strlen(str) + 1];
	char *str2 = (char*) malloc(strlen(str) + 1);
	//printf("str: %s\n", str);
	strcpy(str2, str);
	//printf("str2: %s\n", str2);
	return str2;
}

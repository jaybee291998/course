#include <stdio.h>

int main() {
	const char* str = "jayvee";
	char a = *(str + 1);
	char b = str[1];
	printf("a: %c\n", a);
	printf("b: %c\n", b);

	int c = 69;
	int* cp = &c;
	char c0 = *(cp + 0);
	char c1 = *(cp + 1);
	char c2 = *(cp + 2);
	char c3 = *(cp + 3);



	printf("c0: %d\n", c0);
	printf("c1: %d\n", c1);
	printf("c2: %d\n", c2);
	printf("c3: %d\n", c3);
	return 0;
}

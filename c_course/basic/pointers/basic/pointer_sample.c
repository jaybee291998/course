#include <stdio.h>

int main() {
	int a = 69;
	int *p = &a;
	printf("pointer: %p\n", (void *)p);
	printf("size: %ld\n", sizeof(p));
	return 0;
}

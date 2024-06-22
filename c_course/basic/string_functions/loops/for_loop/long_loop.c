#include <stdio.h>

int main() {
	for(int i = 0; i < 1000000; i++) {
		for(int j = 0; j < 1000000; j++) {
			printf("(%d, %d)\n", i, j);
		}
	
	}
	return 0;
}

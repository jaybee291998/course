#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

size_t mystrlen(const char* str);
size_t randIntGivenBoundary(size_t min, size_t max);
void reverseGivenString(char *str);

int main() {
	srand(time(NULL));
//	char str[100];
//	char mutatedChar[100];
//
//	printf("enter name: ");
//	scanf("%99s", str);
//	size_t len = mystrlen(str);
//	printf("len: %zu\n", len);
//	
//	size_t i = 0;
//	while(*(str + i) != '\0') {
//		size_t pos1 = randIntGivenBoundary(0, len - 2);
//		size_t pos2 = randIntGivenBoundary(pos1 + 1, len - 1);
//	
//		printf("pos1: %zu, pos2: %zu\n", pos1, pos2);
//
//		*(mutatedChar + pos1) = *(str + pos2);
//		*(mutatedChar + pos2) = *(str + pos1);
//		i++;
//	}
//
//	printf("mutatedChar: %s\n", mutatedChar);
//	size_t totalLoops = 100000000;
//	size_t zeroTotal = 0;
//	size_t oneTotal = 0;
//	size_t i = 0;
//	while(i < totalLoops) {
//		size_t res = randIntGivenBoundary(0, 1);
//		switch(res) {
//			case 0:
//				zeroTotal++;
//				break;
//			case 1:
//				oneTotal++;
//				break;
//			default:
//				printf("FUCKKKKKKK");
//		}
//		i++;
//	}
//	double zeroPercentage = (double) zeroTotal / (double) totalLoops;
//	double onePercentage = (double) oneTotal / (double) totalLoops;
//
//	printf("out of %zu tries\n", totalLoops);
//	printf("zero %.4f\n%%", zeroPercentage);
//	printf("one %.4f\n%%", onePercentage);
	char str[] = "jayvee";
	size_t len = mystrlen(str);
	printf("str: %s\n", str);
	
	//char temp = *str;
//	*str = *(str + (len - 1));
//	*(str + (len - 1)) = temp;
	reverseGivenString(str);
	printf("str: %s\n", str);

	return 0;
}

void reverseGivenString(char *str) {
	size_t len = mystrlen(str);
	size_t mid = (len / 2) - 1;
	size_t i = 0;
	size_t j = len - 1;
	while(i < mid) {
		char temp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = temp;
		i++;
		j--;
	}
}

size_t mystrlen(const char* str) {
	size_t len = 0;
	while(*(str + len) != '\0') {
		len++;
	}
	return len;
}

size_t randIntGivenBoundary(size_t min, size_t max) {
	return (rand() % (max - min + 1)) + min;
}



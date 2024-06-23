#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car {
	char brand[50];
	char model[50];
	size_t year;
} car;

int main() {
	car  car1;
	char *brand = "toyota";
	char *model = "electric";
	strcpy(car1.brand, brand);
	strcpy(car1.model, model);
//	car->year = 2024;
	printf("model: %s\n", car1.model);
	printf("brand: %s\n", car1.brand);
	
	return 0;
}

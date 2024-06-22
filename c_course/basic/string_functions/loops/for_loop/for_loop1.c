#include <stdio.h>
#include <stdlib.h>

int main() {
	float remainingCapacity;
	float totalCapacity;
	printf("enter remaing capacity and total capacity: ");
	scanf("%f%f", &remainingCapacity, &totalCapacity);
	// some sanitation
	
	if(totalCapacity == 0) {
		fprintf(stderr, "total capacity cant be zero\n");
		exit(EXIT_FAILURE);	
	}

	if(remainingCapacity > totalCapacity) {	
		fprintf(stderr, "remaining capacity %f  must not be greater than total capacity %f\n ", remainingCapacity, totalCapacity);
		exit(EXIT_FAILURE);	
	}
	
	float capacityUtilizationPercentage;
	return 0;
}

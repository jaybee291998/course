#include<stdio.h>

int main() {
	int a = 69;
	int *p = &a;
	int *p0 = p + 1; 
	// pointer arithmetic
	printf("p is %p\n",(void *) p);
	printf("p + 1 is %p\n",(void *) (p + 1));
	printf("*(p + 1) is %d\n",*(p + 1)); // derefence p + 1
	// try to assign to p + 1
	//*p0 = 420; // segfault haha
	//printf("*(p + 1) is %d\n",*(p + 1)); // derefence p + 1

	// char pointer
	char c = 'c';
	char *pc = &c;
	char *pc0 = pc + 1;
	printf("c is %d\n", c);
	printf("c has a size of %ld\n", sizeof(c));
	printf("pc is %p\n",(void *) pc);
	printf("pc + 1 is %p\n",(void *) (pc + 1));
	printf("*(pc + 1) is %d\n",*pc0); // derefence p + 1
	// char 2
	char c1 = 'y';
	char *pc1 = &c1;
	char *pc01 = pc1 + 1;
	printf("c1 is %d\n", c1);
	printf("c1 has a size of %ld\n", sizeof(c1));
	printf("pc1 is %p\n",(void *) pc1);
	printf("pc1 + 1 is %p\n",(void *) (pc1 + 1));
	printf("*(pc1 + 1) is %d\n",*pc01); // derefence p + 1
	// char pointer
	double d = 69.420;
	char *pd = &d;
	char *pd0 = pd + 1;
	printf("d is %f\n",d);
	printf("d has a size of %ld\n", sizeof(d));
	printf("pd is %p\n",(void *) pd);
	printf("pd + 1 is %p\n",(void *) (pd + 1));
	printf("*(pc + 1) is %f\n",*pd0); // derefence p + 1
	return 0;
} 

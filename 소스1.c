#include<stdio.h>

int fun(int *i) {
	*i += 5;
	return 4;
}

void main() {

	int x = 3;
	x = x + fun(&x);
	printf("%d \n", x);
}
#include <stdio.h>
int f(int a, int i) {
	return a+i;
}

int y( int *a[][2], int b ) {
	return *a+b;
}

int main() {
	int *x[3];
	int b[3];
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	x[0] = b;
	x[1] = b+1;
	x[2] = b+2;
/*
	int c;
	int a;
	int d;
	int i;
	int j;
	int k;
	// printf("%d\n", ++*f(b,1));
	c = -1;
	a+*b*c - d >= i&j + k;

	d = c ++ ++ +a;

	printf("%d\n", 1 >= 2 >= 1 );
*/}
#include<stdio.h>

int main() {
	int x0[3] = {1,2,3};
	int x1[3] = {4,5,6};
	int x2[3] = {7,8,9};

	int *a[3] = {x0, x1, x2};
	printf("%d\n", **a);
}
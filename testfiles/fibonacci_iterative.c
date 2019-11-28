int main() {
	int a[10], int i;
	for( i=0; i<2; i += 1 ) {
		a[i] = i;
	}
	for( i=2; i<10; i += 1 ) {
		a[i] = a[i-1] + a[i-2];
		output(a[i]);
	}

}
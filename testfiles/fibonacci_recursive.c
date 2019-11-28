int fib( int n ) {
	if( n < 2 ) {
		return n;
	}
	return fib(n-1) + fib(n-1);
}

int main() {
		// output(fib(5));
	int i;
	for(i=0; i<=4; i += 1) {
		output(fib(i));
	}
}
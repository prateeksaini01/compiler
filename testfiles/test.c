void mergesort( int a[1024], int l, int r ) {
	int m;
	m = (l+r)/2;
	mergesort(a, l, m);
	mergesort(a, m+1, r);
	int c[1024], int i, int j, int k;
	i=l; j=m;
	for( ; i<m && j<r; ) {
		if( a[i] < a[j] ) {
			;
		}
	}
}
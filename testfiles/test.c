void mergesort( int a[1024], int l, int r ) {
    int m;
    m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    int c[1024], i, j, k;
    for( i=l, j=m; i<m && j<r; i+=0 ) {
        if( a[i] < a[j] ) {
            
        }
    }
}
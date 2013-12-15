int partition(int a[], int l, int r) {
	int q = a[l];
	int i = l;
	int j = i;
	while (j <= r) {
		if (a[j] < q) {
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		++j;
	}
	
	a[l] = a[i];
	a[i] = q;
	
	return i;
}

int numberMoreThanHalf(int a[], int length) {
	if (!a || length <= 0)
		throw new exception();
	
	int middle = length-1/2;
	int l = 0;
	int r = length-1;
	int q = partition(a, l, r);
	
	while (q != middle) {
		if (q < middle) {
			l = q+1;
		} else {
			r = q-1;
		}
		q = partition(a, l, r); 
	}
	
	return a[q];
}
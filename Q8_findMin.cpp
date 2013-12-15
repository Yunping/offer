int findMin(int a[], int length) {
	if (!a)
		throw new exception("NULL Array!");
	
	int l = 0;
	int r = length - 1;
	int m = (l+r) / 2;
	
	if (l == r) return a[m];
	
	while (l < r) {
		if (a[m] < a[r])
			r = m;
		else if (a[m] > a[r])
			l = m + 1;
		else {
			if (a[m] == a[l])
				return findMinInOrder(a, l, r);
			else if (a[m] < a[l])
				r = m;
			else
				return a[l];
		}
	}
	
	return a[];
}
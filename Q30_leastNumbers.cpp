int partition(int a[], int l, int r) {
	int i = l;
	int j = l + 1;
	int p = a[l];
	for (; j <= r; ++j) {
		if (a[j] < p) {
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	
	a[l] = a[i];
	a[i] = p;
	
	return i;
}

vector<int> GetLeastNumbers(int a[], int length, int k) {
	if (!a || length < 0 || k < 0 || k > length)
		throw new exception("illegle input!");
		
	if (k == length)
		return vector<int>(a, a+length);
		
	int middle = length >> 1;
	int l = 0;
	int r = length - 1;
	int q = partition(a, l, r);
	while (q != k-1) {
		if (q < k-1)
			l = q + 1;
		else
			r = q - 1;
		q = partition(a, l, r);
	}
	
	return vector<int>(a, a+k);
}
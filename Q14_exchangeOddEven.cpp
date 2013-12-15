void ExchangeOddEven(int a[], int length) {
	int l = 0;
	int r = length - 1;
	while (l < r) {
		int left = a[l];
		int right = a[r];
		if (!(left & 0x1) && right & 0x1) {
			a[r] = left;
			a[l] = right;
		}
		if (!(right & 0x1))
			--r;
		if (left & 0x1)
			++l;
	}
}
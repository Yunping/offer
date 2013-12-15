std::pair<int, int> twoNumsForSum(int a[], int len, int sum) {
	if (!a || len <= 1) {
	}
	
	int l = 0;
	int r = len - 1;
	int s = a[l] + a[r];
	while (s != sum && l < r) {
		if (s > sum)
			--r;
		if (s < sum)
			++l;
	}
	
	if (s != sum) {
	}
	
	return std::pair<int, int>(a[l], a[r]);
}
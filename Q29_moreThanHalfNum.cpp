// Q29
// Solution 1
int Partition(int a[], int start, int end) {
	if (start == end)
		return start;
	
	int d = a[start];
	int i = start;
	int j = i + 1;
	while (j <= end) {
		if (a[j] > d) {
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		++j;
	}
	
	a[start] = a[i];
	a[i] = d;
	return i;
}

/*int moreThanHalfNum(int a[], int len) {
	int start = 0;
	int end = len - 1;
	int middle = len>>1;
	
	int p = Partition(a, start, end);
	while (p != middle) {
		if (p > middle)
			end = p - 1;
		if (p < middle)
			start = p + 1;
		
		p = Partition(a, start, end);
	}
	
	return a[p];
}*/

// Solution2
int moreThanHalfNum(int a[], int len) {
	int ret = a[0];
	int times = 1;
	for (int i = 1; i < len; ++i) {
		if (times == 0) {
			ret = a[i];
			times = 1;
		} else {
			if (a[i] == ret)
				++times;
			else
				--times;
		}
	}
	
	return ret;
}
void merge(int a[], int len1, int b[], int len2, int c[], int &ret) {
	if (!len1 || !len2) return;
	
	int i = 0, j = 0, k = 0;
	
	while (i < len1 && j < len2) {
		if (a[i] <= b[j]) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
			ret += (len1 - i);	// 此处值得注意，每次递增的数目不是1，而是a中所有比b[j]大的个数
		}
	}
	while (i < len1) {
		c[k++] = a[i++];
	}
	while (j < len2)
		c[k++] = b[j++];
	
	for (k = 0; k < len1 + len2; ++k) {
		a[k] = c[k];
	}
}

void doCalc(int a[], int start, int end, int c[], int& ret) {
	if (end - start > 0) {
		int m = (start + end)/2;
		doCalc(a, start, m, c, ret);
		doCalc(a, m+1, end, c+m+1, ret);
		merge(a+start, m-start+1, a+m+1, end-m, c, ret);
	}
}

int calcReversePair(int a[], int len) {
	int ret = 0;
	if (len > 0) {
		int *c = new int[len];
		doCalc(a, 0, len-1, c, ret);
		delete []c;
	}
	return ret;
}
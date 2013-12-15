struct Range {
	int begin;
	int end;
};

Range findRangeOfNum(int a[], int len, int target) {
	Range ret;
	int l = 0;
	int r = len - 1;
	while (l <= r && l >= 0 && r <= len-1) {
		int m = (l+r)/2;
		if (a[m] <= target)
			l = m+1;
		else
			r = m-1;
	}
	
	ret.end = l-1;
	l = 0;
	r = len - 1;
	while (l <= r && l >= 0 && r <= len-1) {
		int m = (l+r)/2;
		if (a[m] >= target)
			r = m-1;
		else
			l = m+1;
	}
	
	ret.begin = r+1;
	
	return ret;
}
int compare(const void* l, const void* r) {
	return *(int*)l - *(int*)r;
}

bool isContinuous(int a[], int len) {
	if (!a || len <= 0) {
	}
	qsort(a, len, sizeof(int), compare);
	
	// calc zero count
	int zeroCount = 0;
	for (int i = 0; i < len; ++i) {
		if (a[i] == 0)
			++zeroCount;
	}
	
	// calc interval
	int interVals = 0;
	int left = -1;
	int right = -1;
	for (int i = 0; i < len; ++i) {
		if (a[i] != 0) {
			if (first == -1)
				first = i;
			else {
				if (a[i] == a[first])
					return false;
				
				interVals += (a[i] - a[first] - 1);
				first = i;
			}
		}
	}
	
	return (intervals == zeroCount);
}
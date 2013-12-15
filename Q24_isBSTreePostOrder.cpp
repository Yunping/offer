bool isBSTreePostOrder(int a[], int length) {
	if (!a || length <= 0) return false;
	int root = a[length - 1];
	
	int i = 0;
	for (; i < length - 1; ++i) {
		if (a[i] > root)
			break;
	}
	
	int j = i;
	for (; j < length - 1; ++j) {
		if (a[j] < root)
			return false;
	}
	
	bool left = true;
	if (i > 0)
		left = isBSTreePostOrder(a, i);
	if (!left) return false;
	
	bool right = true;
	if (length - 1 - j > 0)
		right = isBSTreePostOrder(a + j, length - 1 - j);
	
	return right;
}	
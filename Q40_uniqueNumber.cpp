int oneUniqueNumber(int a[], int len) {
	if (!a || len <= 0) {
	}
	
	int ret = a[0];
	for (int i = 1; i < len; ++i) {
		ret = ret ^ a[i];
	}
	
	return ret;
}

std::pair<int, int> twoUniqueNumber(int a[], int len) {
	std::pair<int, int> ret;
	if (!a || len <= 0) {
	}
	int temp = a[0];
	for (int i = 1; i < len; ++i) {
		temp = temp ^ a[i];
	}
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < len; ++i) {
		// 为了保证两个唯一数字能够分开，考虑利用它们异或的结果temp作为标准
		// 将整个数组分成两组。
		int t = (temp ^ (temp & (temp - 1))) & a[i];
		if (t & 0x1)
			num1 = num1 ^ a[i];
		else
			num2 = num2 ^ a[i];
	}
	
	ret.first = num1;
	ret.second = num2;
	
	return ret;
}
// 以下是自己考虑的答案，应用了动态规划。思路正确
// 但动态规划不一定非要使用递归实现，一般采用递归的思路分析，循环的方式实现代码
struct cache {
	bool valid;
	int value;
	cache() : valid(false), value(0) {}
	void setValue(int v) {
		value = v;
		valid = true;
	}
};

int func(int a[], int i, cache results[]) {
	if (results[i].valid)
		return results[i].value;
		
	if (i == 0) {
		results[i].setValue(a[i]);
	} else {
		int temp = func(a, i-1, results);
		if (temp < 0)
			results[i].setValue(a[i]);
		else
			results[i].setValue(a[i] + temp);
	}
	
	return results[i].value;
}

int maxSumOfArray(int a[], int length) {
	if (!a || length <= 0)
		return -1;
	cache *results = new cache[length];
	int max = func(a, 0, results);
	for (int i = 1; i < length - 1; ++i) {
		int result_i = func(a, i, results);
		if (max < result_i)
			max = result_i;
	}
	
	delete []results;
	return max;
}

//-----------------------------------------------------
int maxSumOfArray(int a[], int length) {
	int *results = new int[length];
	int max = ~(((unsigned)(~0))>>1);
	for (int i = 0; i < length; ++i) {
		if (i == 0 || results[i-1] < 0)
			results[i] = a[i];
		else
			results[i] = results[i-1] + a[i];
		if (max < results[i])
			max = results[i];
	}
	
	delete []results;
	return max;
}

int maxSumOfArray(int a[], int len) {
	int curSum = 0;
	int maxSum = ~((unsigned int)(-1)>>1);
	
	for (int i = 0; i < len; ++i) {
		if (i == 0 || curSum < 0)
			curSum = a[i];
		else {
			curSum += a[i];
		}
		
		if (maxSum < curSum)
			maxSum = curSum;

	}
	
	return maxSum;
}





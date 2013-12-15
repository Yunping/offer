long long Fibonacci(unsigned int n) {
	int f0 = 0;
	int f1 = 1;
	if (n == 0) return f0;
	if (n == 1) return f1;
	
	int fn_1 = f0;
	int fn_2 = f1;
	int fn;
	for (int i = 2; i <= n; ++i) {
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	
	return fn;
}
int countBitOne(int n) {
	int count = 0;
	while (n) {
		n = n&(n-1);
		++count;
	}
	
	return count;
}

int countBitOne2(int n) {
	int count = 0;
	int flag = 1;
	while (flag) {
		if (flag & n)
			++count;
		flag = flag << 1;
	}
	
	return count;
}
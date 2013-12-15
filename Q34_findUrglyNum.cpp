int min(int v1, int v2, int v3) {
	if (v1 < v2)
		return v1 < v3 ? v1 : v3;
	else
		return v2 < v3 ? v2 : v3;
}

int findUrglyNumber(int index) {
	if (index <= 0) return -1;

	int *urglyNums = new int[index];
	urglyNums[0] = 1;
	int next = 1;
	int temp2 = 0;
	int temp3 = 0;
	int temp5 = 0;
	while (next < index) {
		int nextNum = min(2*urglyNums[temp2], 3*urglyNums[temp3], 5*urglyNums[temp5]);
		urglyNums[next] = nextNum;
		while (urglyNums[temp2] * 2 <= urglyNums[next])
			++temp2;
		while (urglyNums[temp3] * 3 <= urglyNums[next])
			++temp3;
		while (urglyNums[temp5] * 5 <= urglyNums[next])
			++temp5;
		++next;
	}

	return urglyNums[index - 1];
}
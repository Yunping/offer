void calcPairs(int a[], int l, int r, int& count);
int inversePairs(int a[], int len) {
	// todo: verify the array
	int count = 0;
	calcPairs(a, 0, len-1, count);
	
	return count;
}

void doCalc(int a[], int l1, int r1, int l2, int r2, int& count);
void calcPairs(int a[], int l, int r, int& count) {
	if (l < r) {
		int m = (l+r)/2;
		calcPairs(a, l, m, count);
		calcPairs(a, m+1, r, count);
		doCalc(a, l, m, m+1, r, count);
	}
}

void doCalc(int a[], int l1, int r1, int l2, int r2, int& count) {
	if (l1 <= r1 && l2 <= r2) {
		int len = r1 - l1 + r2 - l2 + 2;
		int *temp = new int[len];
		int p1 = l1;
		int p2 = l2;
		int index = 0;
		while (p1 <= r1 && p2 <= r2) {
			if (a[p1] <= a[p2]) {
				temp[index++] = a[p1];
				++p1;
			} else {
				temp[index++] = a[p2];
				count += (r1 - p1 + 1);
				++p2;
			}
		}
		while (p1 <= r1) {
			temp[index++] = a[p1++];
		}
		
		while (p2 <= r2) {
			temp[index++] = a[p2++];
		}
		
		for (int i = l1; i <= r2; ++i) {
			a[i] = temp[i-l1];
		}
		
		delete []temp;
	}
}
void posibility(int num, int current, int sum, int *results) {
	if (current == num) {
		results[sum-num]++;
	} else {
		for (int v = 1; v <= 6; ++v) {
			posibility(num, current+1, sum+v, results);
		}
	}
}

void calcPosibility(int num, int **results) {
	if (!results || num < 1) return;
	*results = new int[5*num+1];
	for (int i = 0; i < 5*num+1; ++i)
		(*results)[i] = 0;
	posibility(num, 0, 0, *results);
}

void printPosibility(int num) {
	int *results = 0;
	calcPosibility(num, &results);
	if (!results) return;
	float total = pow((float)6, num);
	for (int s = num; s <= 6*num; ++s) {
		printf("posibility of %d is %f\n", s, results[s-num] / total);
	}
}

void printPosibility(int num) {
	if (num < 1) return;
	int *results = new int[6*num];
	for (int i = 0; i < 6*num; ++i)
		results[i] = 0;
	
	int *temp = new int[6*num];
	for (int i = 0; i < 6*num; ++i)
		temp[i] = 0;
	
	for (int i = 0; i < 6; ++i)
		temp[i] = 1;
		
	for (int n = 2; n <= num; ++n) {
		for (int s = 6*n-5; s <= 6*n; ++s) {
			int posi = temp[s-1-1];
			for (int v = 2; v <= 6; ++v) {
				if (s-1-v >= 0)
					posi += temp[s-1-v];
			}
			results[s-1] = posi;
			temp[s-1] = posi;
		}
	}
		
	float total = pow((float)6, num);
	for (int s = num; s <= 6*num; ++s) {
		printf("posibility of %d is %f\n", s, results[s-1] / total);
	}
}



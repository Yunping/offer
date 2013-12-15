bool increase(char *numbers);
void printNumber(char *numbers);
void print1ToMaxOfNDigits(int n) {
	if (n <= 0)
		throw new exception();
	char *numbers = new char[n+1];
	for (int i = 0; i < n; ++i)
		numbers[i] = '0';
	numbers[n] = '\0';
	
	while (increase(numbers)) {
		printNumber(numbers);
	}
	
	delete []numbers;
}

bool increase(char *numbers) {
	int n = strlen(numbers);
	int i = n - 1;
	for (i = n-1; i >=0; --i) {
		if ((numbers[i] - '0') < 9) {
			numbers[i] = char(numbers[i] + 1);
			break;
		} else {
			numbers[i] = '0';
		}
	}
	
	return i >= 0;
}

void printNumber(char *numbers) {
	int len = strlen(numbers);
	for (int i = 0; i < len; ++i) {
		if (numbers[i] != '0') {
			printf("%s\t", numbers+i);
			break;
		}
	}
}

// 递归
void print1ToMaxOfNDigits2(int n) {
	if (n <= 0)
		throw new exception();
	char *numbers = new char[n+1];
	memset(numbers, '0', n);
	numbers[n] = '\0';
	
	doPrint(numbers, 0);
	delete []numbers;
}

void doPrint(char *numbers, int current) {
	int len = strlen(numbers);
	if (current == len) {
		printNumber(numbers);
		return;
	}
	current = current + 1;
	for (int i = 0; i <= 9; ++i) {
		numbers[current-1] = (char)('0' + i);
		doPrint(numbers, current);
	}
}
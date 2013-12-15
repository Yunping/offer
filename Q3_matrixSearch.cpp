bool matrixSearch(int a[][], int row, int col, int target) {
	int rightCol = col - 1;;
	int topRow = 0;
	
	while (rightCol >= 0 && topRow < row) {
		if (a[topRow][rightCol] == target)
			return true;
		if (a[topRow][rightCol] < target)
			++topRow;
		else
			--rightCol;
	}
	
	return false;
}
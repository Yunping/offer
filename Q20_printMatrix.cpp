void printMatrixCircle(int *matrix[], int row, int col, int circle);
void printMatrix(int *matrix[], int row, int col) {
	int circleCount = ((row > col ? col : row) + 1) / 2;
	for (int circle = 0; circle < circleCount; ++circle) {
		printMatrixCircle(matrix, row, col, circle);
	}
}

void printMatrixCircle(int *matrix[], int row, int col, int circle) {
	// left -> right
	// x: circle
	// y: circle -> col - 1 - circle
	int x = circle;
	int y = circle;
	while (y <= col - 1 - circle)
		printf("%d\t", matrix[x][y++]);
	
	// top -> bottom
	// x: circle + 1 -> row - 1 - circle
	// y: col - 1 - circle
	x = circle + 1;
	y = col - 1 - circle;
	while (x <= row - 1 - circle)
		printf("%d\t", matrix[x++][y]);
	
	// right -> left
	// x: row - 1 - circle
	// y: col - 1 - circle - 1 -> circle
	x = row - circle - 1;
	y = col - circle - 2;
	while (y >= circle)
		printf("%d\t", matrix[x][y--]);
	
	// bottom -> top
	// x: row - circle - 2 -> circle + 1
	// y: circle
	x = row - circle - 2;
	y = circle;
	while (x >= circle + 1)
		printf("%d\t", matrix[x--][y]);
}
struct BTree {
	int value;
	BTree *left;
	BTree *right;
	
	BTree(int v) : value(v), left(0), right(0) {}
};

BTree* buildTree(int pre[], int middle[], int length) {
	if (length <= 0) return 0;
	BTree *root = new BTree(pre[0]);
	
	int rootIndex = -1;
	for (int i = 0; i < length; ++i) {
		if (middle[i] == pre[0]) {
			rootIndex = i;
			break;
		}
	}
	
	int leftTreeNodes = rootIndex;
	int rightTreeNodes = length - leftTreeNodes - 1;
	
	root->left = buildTree(pre+1, middle, leftTreeNodes);
	root->right = buildTree(pre+leftTreeNodes+1, middle+rootIndex+1, rightTreeNodes);
	
	return root;
}
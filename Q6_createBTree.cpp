// Question6
BTreeNode* CreateTree(int preOrder[], int middleOrder[], int size) {
	if (size <= 0)
		return 0;
	
	BTreeNode *root = new BTreeNode();
	root->_value = preOrder[0];
	// find the root node in middleOrder
	int rootIndex = 0;
	for (int i = rootIndex; i < size; ++i) {
		if (middleOrder[i] == root->_value) {
			rootIndex = i;
			break;
		}
	}
	root->_left = CreateTree(preOrder+1, middleOrder, rootIndex);
	root->_right = CreateTree(preOrder+rootIndex+1, middleOrder+rootIndex+1, size-rootIndex-1);
	
	return root;
}
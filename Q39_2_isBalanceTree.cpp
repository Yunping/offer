struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

bool isBalanceTree(TreeNode* root, int& height) {
	if (!root) {
		height = 0;
		return true;
	}
	
	int leftHeight = 0;
	int rightHeight = 0;
	if (!isBalanceTree(root->left, leftHeight))
		return false;
	if (!isBalanceTree(root->right, rightHeight))
		return false;
	if (rightHeight-leftHeight < -1 || rightHeight-leftHeight > 1)
		return false;
	height = 1 + (rightHeight > leftHeight ? rightHeight : leftHeight);
	
	return true;
}

bool isBalanceTree(TreeNode* root) {
	int height;
	return isBalanceTree(root, height);
}
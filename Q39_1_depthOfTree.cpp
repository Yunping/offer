struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

int treeDepth(TreeNode *root) {
	if (!root) return 0;
	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);
	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
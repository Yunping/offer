struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

bool hasSubTree(TreeNode *root1, TreeNode *root2) {
	bool result = false;
	if (root1 && root2) {
		if (root1->val == root2->val)
			result = isTree2InTree1(root2, root1);
		if (!result)
			result = hasSubTree(root1->left, root2);
		if (!result)
			result = hasSubTreen(root1->right, root2);
	}
		
	return result;
}

bool isTree2InTree1(TreeNode *root2, TreeNode *root1) {
	if (!root2) return true;
	if (!root1) return false;
	
	if (root2->val != root1->val)
		return false;
	return isTree2InTree1(root2->left, root1->left) && 
			isTree2InTree1(root2->right, root1->right);
}

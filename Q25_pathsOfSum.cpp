struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

void findPathsOfSum(TreeNode *root, int sum, int current, vector<TreeNode*>& ret, vector<vector<TreeNode*> >& paths) {
	if (!root) return;
	
	ret.push_back(root);
	current += root->value;
	if (root->left) {
		findPathsOfSum(root->left, current, ret, paths);
	}
	
	if (root->right) {
		
		findPathsOfSum(root->right, current, ret, paths);
	}
	
	if (!root->left && !root->right) {
		if (current == sum) {
			paths.push_back(ret);
		}
	}
	
	ret.pop_back();
}
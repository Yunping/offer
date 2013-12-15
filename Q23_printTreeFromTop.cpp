struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

void printFromTop(TreeNode *root) {
	if (!root) return;
	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		TreeNode *current = queue.front();
		queue.pop();
		printf("%d\t", current->value);
		if (current->left)
			queue.push(current->left);
		if (current->right)
			queue.push(current->right);
	}
}
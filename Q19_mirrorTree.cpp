struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

TreeNode *mirrorTree(TreeNode *root) {
	if (!root) return 0;
	TreeNode *left = root->left;
	root->left = mirrorTree(root->right);
	root->right = mirrorTree(left);
	
	return root;
}

// 循环实现
TreeNode *mirrorTree2(TreeNode *root) {
	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		TreeNode *node = queue->pop();
		TreeNode *temp = node->left;
		node->left = node->right;
		node->right = temp;
		if (node->left)
			queue.push(node->left);
		if (node->right)
			queue.push(node->right);
	}
	
	return root;
}
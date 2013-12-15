struct Node {
	Node* left;
	Node* right;
};

// 看过提示后的解法
bool isBalanced(Node *root, int& depth) {
	if (!root) {
		depth = 0;
		return true;
	}
	
	int lDepth = 0;
	int rDepth = 0;
	if (isBalanced(root->left, lDepth) && isBalanced(root->right, rDepth)) {
		depth = (lDepth > rDepth ? lDepth : rDepth) + 1;
		if (lDepth - rDepth > 1 || lDepth - rDepth < -1)
			return false;
		return true;
	}
	
	return false;
	
}
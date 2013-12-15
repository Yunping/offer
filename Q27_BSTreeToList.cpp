struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	
	BinaryTreeNode(int v) {
		value = v;
		left = 0;
		right = 0;
	}
};

// 我的答案，正确，但不如书中答案自然
BinaryTreeNode* BSTreeToList(BinaryTreeNode* root) {
	if (root) {
		BinaryTreeNode *leftPart = BSTreeToList(root->left);
		BinaryTreeNode *rightPart = BSTreeToList(root->right);
		if (leftPart) {
			BinaryTreeNode *lastNodeInLeftPart = leftPart;
			while (lastNodeInLeftPart->right) {
				lastNodeInLeftPart = lastNodeInLeftPart->right;
			}
			
			lastNodeInLeftPart->right = root;
			root->left = lastNodeInLeftPart;
		}
		if (rightPart) {
			rightPart->left = root;
			root->right = rightPart;
		}
		
		return leftPart ? leftPart : root;
		
	}
	return 0;
}

// 书中答案
void BSTreeToList(BinaryTreeNode* current, BinaryTreeNode* &currentLast) {
	if (current) {
		BSTreeToList(current->left, currentLast);
		current->left = currentLast;
		if (currentLast)
			currentLast->right = current;
		currentLast = current;
		BSTreeToList(current->right, currentLast);
	}
}

BinaryTreeNode* convert(BinaryTreeNode * root) {
	BinaryTreeNode *last = 0;
	BSTreeToList(root, last);
	while (last && last->left) {
		last = last->left;
	}
	
	return last;
}
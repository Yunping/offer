struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* tailOfList(TreeNode* head) {
	TreeNode *cur = head;
	while (cur && cur->right) {
		cur = cur->right;
	}
	
	return cur;
}

TreeNode* BSTreeToDoubleLinkedList(TreeNode *root) {
	TreeNode *head = root;
	if (root) {
		if (root->left) {
			head = BSTreeToDoubleLinkedList(root->left);
			root->left = tailOfList(head);
			root->left->right = root;
		}
		
		if (root->right) {
			root->right = BSTreeToDoubleLinkedList(root->right);
			root->right->left = root;
		}
	}
	
	return head;
}
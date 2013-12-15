struct Node {
	int value;
	Node *next;
};

Node* deleteListNode(Node *head, Node *node) {
	if (!node) return;
	
	Node *nextNode = node->next;
		
	if (nextNode) {
		node->value = nextNode->value;
		node->next = nextNode->next;
		delete nextNode;
	} else {
		Node *cur = head;
		while (cur->next && cur->next != node) {
			cur = cur->next;
		}
		
		if (cur->next) {
			cur->next = 0;
			delete node;
		} else {
			// head must be node
			delete node;
			head = 0;
		}
	}
	
	return head;
	
}
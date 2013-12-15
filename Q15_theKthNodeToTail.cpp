struct Node {
	int value;
	Node *next;
};

Node* kthNodeToTail(Node *head, int k) {
	// k <= 0
	if (k <= 0)
		return 0;
	
	// k > size
	Node *cur = head;
	Node *ret = head;
	int steps = 0;
	while (cur) {
		if (steps == k)
			ret = ret->next;
		else
			++steps;
		cur = cur->next;
	}
	
	return steps == k ? ret : 0;
}
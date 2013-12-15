struct Node {
	int value;
	Node *next;
};

Node* firstSharedNode(Node *list1, Node* list2) {
	stack<Node*> stack1;
	stack<Node*> stack2;
	Node *it = list1;
	while (it) {
		stack1.push(it);
		it = it->next;
	}
	
	it = list2;
	while (it) {
		stack2.push(it);
		it = it->next;
	}
	
	Node* top1 = stack1.top();
	Node* top2 = stack2.top();
	while (!stack1.empty() && !stack2.empty()) {
		if (top1 == top2)
			return top1;
		stack1.pop();
		stack2.pop();
	}
	
	return 0;
}
struct Node {
	Node *next;
	int value;
};

Node* firstCommonNode(Node *list1, Node *list2) {
	int len1 = 0;
	Node *p = list1;
	while (p) {
		++len1;
		p = p->next;
	}
	
	int len2 = 0;
	p = list2;
	while (p) {
		++len2;
		p = p->next;
	}
	
	int offset = len1 > len2 ? len1 - len2 : len2 - len1;
	p = len1 > len2 ? list1 : list2;
	while (offset) {
		p = p->next;
		--offset;
	}
	
	p = len1 > len2 ? list1 : list2;
	Node *q = ((p == list1) ? list2 : list1);
	while (p && q) {
		if (p == q)
			return p;
		p = p->next;
		q = q->next;
	}
	
	return 0;
}
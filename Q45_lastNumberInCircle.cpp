// Q45_lastNumberInCircle;

struct Node{
	int value;
	Node* next;
	Node* previous;
};

int lastNumInCircle(int n, int m) {
	if (n <= 0 || m <= 0) return -1;
	if (n == 1) return 0;
	
	// build linktable:
	Node *firstNode = new Node();
	firstNode->value = 0;
	firstNode->next = 0;
	firstNode->previous = 0;
	
	Node *previousNode = firstNode;
	for (int i = 1; i < n; ++i) {
		previousNode->next = new Node();
		previousNode->next->value = i;
		previousNode->next->next = 0;
		previousNode->next->previous = previousNode;
		previousNode = previousNode->next;
	}
	previousNode->next = firstNode;
	firstNode->previous = previousNode;
	
	// delete the mth number
	int deleted = 0;
	Node *p = firstNode;
	Node *next = 0;
	while (deleted < n-1) {
		int count = 1;
		while (count < m) {
			p = p->next;
			++count;
		}
		next = p->next;
		p->previous->next = p->next;
		delete p;
		p = next;
		++deleted;
	}
	
	int ret = next->value;
	delete next;
	return ret;
}
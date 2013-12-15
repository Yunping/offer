struct ListNode {
	int value;
	ListNode* next;
};

ListNode* reverseNode(ListNode *head) {	
	ListNode *prev = 0;
	ListNode *cur = head;
	ListNode *next = 0;
	
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	return prev;
}

// 递归实现
ListNode *reverseNode(ListNode *cur, ListNode* prev) {
	if (!cur) return prev;
	ListNode* next = cur->next;
	cur->next = prev;
	
	return reverseNode(next, cur);
}
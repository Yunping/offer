struct ListNode {
	int value;
	ListNode *next;
};

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if (!head1) return head2;
   	if (!head2) return head1;
   	ListNode* cur1 = head1;
   	ListNode* cur2 = head2;
   	ListNode* sorted = 0;
   	ListNode* head = 0;
   	while (cur1 && cur2) {
   		if (cur1->val < cur2->val) {
   			if (sorted) {
   				sorted->next = cur1;
   				sorted = cur1;
   				cur1 = cur1->next;
   			} else {
   			    head = cur1;
   			    sorted = cur1;
   				cur1 = cur1->next;
   			}
   		} else {
   			if (sorted) {
   				sorted->next = cur2;
   				sorted = cur2;
   				cur2 = cur2->next;
   			} else {
   			    head = cur2;
   			    sorted = cur2;
   				cur2 = cur2->next;
   			}
   		}
   	}
   	
   	while (cur1) {
   		sorted->next = cur1;
   		sorted = cur1;
   		cur1 = cur1->next;
   	}
   	
   	while (cur2) {
   		sorted->next = cur2;
   		sorted = cur2;
   		cur2 = cur2->next;
   	}
   	
   	return head;
}

// 递归方法进行merge
ListNode *mergeSortedLists(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;
	
	if (l1->val < l2->val) {
		l1->next = mergeSortedLists(l1->next, l2);
		return l1;
	} else {
		l2->next = mergeSortedLists(l1, l2->next);
		return l2;
	}
}



#include "../base.h"
/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.*/

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode Dummy(-1);
		if (head == NULL) return NULL;
		Dummy.next = head;
		ListNode *l1 = &Dummy;
		//Dummy.next = head->next;
		ListNode *l2 = head;
		ListNode *l3 = head->next;
		for (;l3!=NULL;) {//需要修改的指针有三个
			l2->next = l3->next;
			l3->next = l2;
			l1->next = l3;
			l1 = l2;
			l2 = l2->next;
			if (l2)
				l3 = l2->next;
			else
				break;
		}
		return Dummy.next;
	}
	
};
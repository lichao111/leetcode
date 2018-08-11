#include "../base.h"

/*Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {O(k1+k2)
		ListNode Tmp(-1);
		ListNode* p = &Tmp;
		ListNode *p1 = l1, *p2 = l2;
		for (; p1!= NULL&&p2!= NULL; ) {
			if (p1->val <= p2->val) {
				p->next = p1;
				p = p->next;
				p1 = p1->next;
			}
			else {
				p->next = p2;
				p = p->next;
				p2= p2->next;
			}
		}
		if (p1 == NULL) {
			p->next = p2;
		}
		else {
			p->next = p1;
		}

		return Tmp.next;
	}
};
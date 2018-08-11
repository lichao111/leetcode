#include "../base.h"

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		ListNode* ls = *lists.begin();
		for (vector<ListNode*>::iterator iter = lists.begin()+1; iter != lists.end(); iter++) {//遍历k次
			ls = this->mergeTwoLists(ls, *iter);//mergerTwoLists的复杂度是  O（）
		}
		return ls;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode Tmp(-1);
		ListNode* p = &Tmp;
		ListNode *p1 = l1, *p2 = l2;
		for (; p1 != NULL&&p2 != NULL; ) {
			if (p1->val <= p2->val) {
				p->next = p1;
				p = p->next;
				p1 = p1->next;
			}
			else {
				p->next = p2;
				p = p->next;
				p2 = p2->next;
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
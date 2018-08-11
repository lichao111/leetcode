#include "../base.h"
/*For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {//O(k)
		cout << "99999" << endl;
		if (!head||1==k) return head;//head为空，直接返回
		//ListNode Dummy(-1);
		//Dummy.next = head;
		ListNode *cur = head;
		int n = k;
		n--;
		while (n--)//判断长度是否足够  （找到第k个节，不够k个返回头结点）
		{
			if (cur)
			{
				cur = cur->next;
			}
			if (cur) {
				continue;
			}
			else {
				return head;
			}
		}
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		int m = k-1;
		while (m--)
		{
			head->next = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = head->next;
		}
		//head->next = reverseKGroup(head->next,k);
		head->next = this->reverseKGroup(head->next, k);
		//cout << head->next->val << endl;
		cout << "---------" << endl;
		return p1;
	}
};
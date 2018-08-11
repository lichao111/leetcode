#include "../base.h"

/**
* Definition for singly-linked list./*
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/*   Given linked list: 1->2->3->4->5, and n = 2.
						{0,4,-5,2,-2,4,2,-1,4};
   After removing the second node from the end, the linked list becomes 1->2->3->5.*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {//为了使头节点不用作特殊处理，需要再加一个头节点
		ListNode TmpHead(-1);
		TmpHead.next = head;
		ListNode* p_Node = &TmpHead;
		ListNode* cheak = p_Node;
		int k = n+1;
		while (1) {
			while (k--)
			{
				cheak = cheak->next;
			}
			if (cheak) {
				cheak = p_Node->next;
				p_Node = p_Node->next;
				k = n+1;
			}
			else
			{
				cout << p_Node->val << endl;
				p_Node->next = p_Node->next->next;
				break;
			}
		}
		return TmpHead.next;
		//DisplayLiseNode(head);
	}
};
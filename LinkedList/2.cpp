#include "../base.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//Example
//
//Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.
class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode t_List(0), *p = &t_List;
		ListNode* t_tmp1 = l1;
		ListNode* t_tmp2 = l2;
		int t_ndigit = 0;
		
		while (t_tmp1||t_tmp2||(t_ndigit!=0))
		{
			int value1 = t_tmp1 ? t_tmp1->val : 0;
			int value2 = t_tmp2 ? t_tmp2->val : 0;
			p->next = new ListNode((value1+value2+t_ndigit)%10);
			p = p->next;
			t_ndigit = (value1 + value2 + t_ndigit) / 10;
			t_tmp1 = t_tmp1 ? t_tmp1->next : t_tmp1;
			t_tmp2 = t_tmp2 ? t_tmp2->next : t_tmp2;
		}
		return t_List.next;
	}
};

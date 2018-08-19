#ifndef  _BASE_H_
#define _BASE_H_

#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <string>
#include <math.h>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //打印单链表
 void DisplayLiseNode(ListNode* p) {
	 ListNode* chea = p;
	 //cout << p->val << endl;
	 //cout << chea->val << endl;
	 while (chea)
	 {
		 cout << chea->val << " -> ";
		 chea = chea->next;
	 }
	 cout << "NULL" << endl;
	// cout << "------------" << endl;
 }

 //构造单链表
 ListNode* BuildList(vector<int> seed) {
	 ListNode Dull(-1);
	 ListNode* p_node = &Dull;
	 for (vector<int>::iterator iter = seed.begin(); iter != seed.end(); iter++) {
		 ListNode *tmp = new ListNode(*iter);
		 p_node->next = tmp;
		 p_node = p_node->next;
		// cout << *iter << endl;
	 }
	 //getchar();
	 return Dull.next;
 }


 //打印vector<typename T>
 template<typename T>
	 void Display(vector<T> s) {
		 if (s.size() == 0) {
			 cout << "[ ]" << endl; return;
		 }
		 cout << '[';
	 for (typename vector<T>::iterator iter = s.begin(); iter != s.end()-1; iter++) {
		 cout << *iter << ",";
	 }
	 cout << *(s.end() - 1) << ']';
	 cout << endl;
 }

 //打印vector<vector<typename T>>
 template<typename T>
	 void DisplayVecofVec(vector<vector<T> > base) {
		 int t_nLen = base.size();
		 if (0 == t_nLen) {
			 cout << "[" << endl << "[]" << endl << "]"<< endl;
			 return;
		 }
		 cout << "[" << endl;
		 
		 for (int i = 0;i < t_nLen ;i++ )
		 {
			 Display(base[i]);
		 }
		 cout << "]" << endl;

	 }

template<typename T1,typename T2>
	void Displaymap(map<T1,T2> base){
		int t_nLen = base.size();
		if(0==t_nLen)
		{
			cout<<"{"<<endl<<"}"<<endl;
			return;
		}
		cout<<"{";
		for(typename map<T1,T2>::iterator iter = base.begin(); (iter) != base.end(); iter++)
		{
			cout<<iter->first<<":"<<iter->second<<", ";
		}
		//cout<<(*(base.end()-1)).first<<":"<<(*(base.end()-1)).second<<endl;
		cout<<"}"<<endl;
	}
#endif // ! _BASE_H_


#ifndef _BASE_H_
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
#include <sys/time.h>
using namespace std;

class Timer
{
  public:
	void TimeStart();
	void TimeStop();

	void TimeUsr();

  private:
	struct timeval t1;
	struct timeval t2;
};

void Timer::TimeStart()
{
	gettimeofday(&t1, NULL);
}
void Timer::TimeStop()
{
	gettimeofday(&t2, NULL);
}
void Timer::TimeUsr()
{
	double timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
	cout << endl;
	cout << "------------------" << endl;
	cout << "Run time: " << timeuse * 1000 << " ms" << endl;
	cout << "------------------" << endl;
}

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//打印单链表
void DisplayLiseNode(ListNode *p)
{
	ListNode *chea = p;
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
ListNode *BuildList(vector<int> seed)
{
	ListNode Dull(-1);
	ListNode *p_node = &Dull;
	for (vector<int>::iterator iter = seed.begin(); iter != seed.end(); iter++)
	{
		ListNode *tmp = new ListNode(*iter);
		p_node->next = tmp;
		p_node = p_node->next;
		// cout << *iter << endl;
	}
	//getchar();
	return Dull.next;
}

//打印vector<typename T>
template <typename T>
void Display(vector<T> s)
{
	if (s.size() == 0)
	{
		cout << "[ ]" << endl;
		return;
	}
	cout << '[';
	for (typename vector<T>::iterator iter = s.begin(); iter != s.end() - 1; iter++)
	{
		cout << *iter << ",";
	}
	cout << *(s.end() - 1) << ']';
	cout << endl;
}

//打印vector<vector<typename T>>
template <typename T>
void DisplayVecofVec(vector<vector<T> > base)
{
	int t_nLen = base.size();
	if (0 == t_nLen)
	{
		cout << "[" << endl
			 << "[]" << endl
			 << "]" << endl;
		return;
	}
	cout << "[" << endl;

	for (int i = 0; i < t_nLen; i++)
	{
		Display(base[i]);
	}
	cout << "]" << endl;
}

template <typename T1, typename T2>
void Displaymap(map<T1, T2> base)
{
	int t_nLen = base.size();
	if (0 == t_nLen)
	{
		cout << "{" << endl
			 << "}" << endl;
		return;
	}
	cout << "{";
	for (typename map<T1, T2>::iterator iter = base.begin(); (iter) != base.end(); iter++)
	{
		cout << iter->first << ":" << iter->second << ", ";
	}
	//cout<<(*(base.end()-1)).first<<":"<<(*(base.end()-1)).second<<endl;
	cout << "}" << endl;
}

/************************construct binary tree and travel***********************/
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// void InorerTraverse(TreeNode *T){
// 	InitStck(S); push(S,T);
// 	while(!StackEmpty(S)){
// 		while(GetTop(S,p)&&p) Push(S,p->lchild);
// 		Pop(S,p);
// 		if(!StackEmpty(S)){
// 			Pop(S,p); if(!visit(p->data)) return ERROR;
// 			Push(S,p->rchild);
// 		}//if
// 	}//while
// 	return;
// }

//recursion
void InOrder_recursion(TreeNode *root)
{
	if (root)
	{
		if (root->left)
		{
			InOrder_recursion(root->left);
		}
		cout << root->val << ' ';
		if (root->right)
		{
			InOrder_recursion(root->right);
		}
	}
}

void InOrder(TreeNode *root)
{
	stack<TreeNode *> Node;
	TreeNode *tmp = root;
	Node.push(root);
	while (!Node.empty())
	{
		while (Node.top())
		{ //
			Node.push((Node.top())->left);
		}
		Node.pop();
		if (!Node.empty())
		{
			tmp = Node.top();
			cout << tmp->val << ' ';
			Node.pop();
			Node.push(tmp->right);
		}
	}
}

void PreOrder(TreeNode *root)
{
	stack<TreeNode *> Node;
	TreeNode *tmp = root;
	Node.push(root);
	while (!Node.empty())
	{
		while (Node.top())
		{ //
			cout<<(Node.top())->val<<' ';
			Node.push((Node.top())->left);
		}
		Node.pop();
		if (!Node.empty())
		{
			tmp = Node.top();
			//cout << tmp->val << ' ';
			Node.pop();
			Node.push(tmp->right);
		}
	}
}

void PostOrder(TreeNode *root)
{
	stack<TreeNode *> Node;
	TreeNode *pre = NULL;//记录前一次访问的节点
	TreeNode *cur = NULL;//当前节点
	Node.push(root);
	while (!Node.empty())
	{
		cur = Node.top();
		if((cur->left==NULL&&cur->right==NULL)||
			(pre!=NULL&&(pre==cur->left||pre==cur->right)))
			{
				//当前节点没有孩子或者孩子被访问过
				cout<<cur->val<<' ';
				Node.pop();
				pre=cur;
			}
		else{
			if(cur->right!=NULL)	
				Node.push(cur->right);
			if(cur->left!=NULL)
				Node.push(cur->left);
			
		}
	}
}

void LevelOrder(TreeNode *root){
	
}

#endif // ! _BASE_H_

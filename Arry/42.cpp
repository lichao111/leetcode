#include "../base.h"


/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.*/
class Solution {
public:
	int trap(vector<int>& height) {
		int t_nRes = 0;
		vector<int> t_vecTmp;
		while (true)
		{
			bool t_bOver = true;
			for (vector<int>::iterator iter = height.begin(); iter != height.end(); iter++)
			{
				if (*iter >= 1)
				{
					t_bOver = false;
					(*iter)--;
					t_vecTmp.push_back(1);
				}
				else
				{
					t_vecTmp.push_back(0);
				}
			}
			//Display(height);
			if (t_bOver)
			{
				break;
			}
			else
			{
				t_nRes += this->OneFlowSum(t_vecTmp);
			}
			t_vecTmp.clear();
		}
		return t_nRes;
	}
	int OneFlowSum(vector<int> a)
	{
		int t_nRes = 0;
		bool t_bstarted =false;
		int t_nLen = a.size();
		int t_nStart;
		int t_nEnd;
		for (int i = 0; i < t_nLen; i++)
		{
			if (a[i] == 1)
			{
				t_nStart = i;
				break;
			}
		}
		for (int i = (t_nLen - 1); i >= 0; i--)
		{
			if (a[i] == 1)
			{
				t_nEnd = i;
				break;
			}
		}
		cout << t_nStart << ".." << t_nEnd << endl;
		for (int i = t_nStart; i != t_nEnd; i++)
		{
			if(a[i]==0)
			t_nRes++;
		}
		cout << t_nRes << endl;
	
		return t_nRes;
	}
};
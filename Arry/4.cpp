#include "../base.h"

class Solution {//能pass，但是复杂度O(m+n)不合题目要求O(log(m+n))
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double t_dRes = 0;
		vector<int> t_vecTmp;
		for (vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
			iter1 != nums1.end() || iter2 != nums2.end();)
		{
			//cout << *iter1 << endl;
			if (iter1== nums1.end())
			{
				t_vecTmp.push_back(*iter2);
				iter2++;
			}
			else if (iter2 == nums2.end())
			{
				t_vecTmp.push_back(*iter1);
				iter1++;
			}
			else
			{
				if (*iter1 < *iter2)
				{
					t_vecTmp.push_back(*iter1);
					iter1++;
				}
				else {
					t_vecTmp.push_back(*iter2);
					iter2++;
				}
			}
			//t_vecTmp.push_back();
		}
		int t_nLen = t_vecTmp.size();
		assert(t_nLen == (nums1.size() + nums2.size()));
		if (t_vecTmp.size() % 2 == 0)
		{
			cout << t_vecTmp[t_nLen / 2] << " " << t_vecTmp[(t_nLen / 2) - 1] << endl;
			t_dRes = (t_vecTmp[t_nLen / 2] + t_vecTmp[(t_nLen / 2) - 1]) / 2.0;
		}
		else
		{
			t_dRes = t_vecTmp[t_nLen / 2];
		}
		return t_dRes;
	}

};
#ifndef _SOLUTION_H_
#define _SOLUTION_H_
#include "../base.h"
class Solution {//2018/2/24
public:
	vector<int> twoSum(vector<int>& nums, int target)//O(N)
	{
		vector<int> t_VecRes;
		int t_nLen = nums.size();
		map<int, int> t_mapTmp;
		for (int i = 0; i < t_nLen; i++)
		{
			t_mapTmp.insert(pair< int,int>(nums[i], i));
		}
		for (int i = 0; i < t_nLen; i++)
		{
			map<int, int>::iterator iter = t_mapTmp.find(target - nums[i]);
			if (iter != t_mapTmp.end()&&(iter->second!=i))
			{
				t_VecRes.push_back(i);
				t_VecRes.push_back(iter->second);
				break;
			}
		}
		return t_VecRes;
	}

};


#endif // !_SOLUTION_H_


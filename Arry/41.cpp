#include "../base.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()),nums.end());
		int t_nLen = nums.size();
		assert(t_nLen != 0);
		int start = nums[0];
		int index = 0;
		bool find = true;
		bool b = false;
		for (; index < t_nLen; index++) {
			if (nums[index] > 0&&find)
			{
				find = false;
				b = true;
				start = nums[index];
				if (start != 1)
					return 1;
				continue;
			}
			if(b)
				if (nums[index] != ++start)
				{
					cout << index << endl;
					cout << "--" << endl;
					return start;
				}
		}
		return (nums[t_nLen - 1] + 1)>=1? nums[t_nLen - 1] + 1:1;

	}
};
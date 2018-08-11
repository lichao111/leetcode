#include "../base.h"

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		int t_nLen = nums.size();
		for (int i = 0; i < t_nLen;)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin()+i);
				t_nLen--;
			}
			else {
				i++;
			}
		}
		Display(nums);
		return nums.size();
	}
};
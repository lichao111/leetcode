#include "../base.h"

/*Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
	int removeDuplicates1(vector<int>& nums) {
		int t_nRes = 0;
		int t_nLen = nums.size();
		if (0==t_nLen)
			return 0;
		if (1 == t_nLen)
			return 1;
		sort(nums.begin(), nums.end());
		t_nRes = 1;
		int t_nTemplate = *nums.begin();
		for (int i = 1; i < t_nLen;) {
			if (t_nTemplate != nums[i]) {
				t_nTemplate = nums[i];
				//cout << t_nTemplate << endl;
				t_nRes++;
				i++;
			}
			else {
				//cout << *(nums.begin() + i) << endl;
				nums.erase(nums.begin() + i);
				t_nLen--;
			}
		}
		//cout << "------------" << endl;
		//Display(nums);
		//cout << "------------" << endl;
		return t_nRes;
	}
	int removeDuplicates2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()),nums.end());
		return nums.size();

	}
};
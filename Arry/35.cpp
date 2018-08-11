#include "../base.h"
/*Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		vector<int>::iterator it = find(nums.begin(), nums.end(), target);
		if (it == nums.end()) {//not found
			for (it = nums.begin(); it != nums.end(); it++) {
				if (*it - target > 0)
					return it - nums.begin();
			}
			return nums.size();
		}
		else {//found
			return it - nums.begin();
		}
	}
};
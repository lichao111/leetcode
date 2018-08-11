#include "../base.h"

/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		vector<int>::iterator index = find(nums.begin(), nums.end(), target);
		if (index == nums.end()) {
			return -1;
		}
		int t_nRes = index - nums.begin();
		for (vector<int>::iterator iter = nums.end() - 1; iter >= index; iter--) {
			nums.insert(nums.begin(), *iter);
			nums.pop_back();
		}
		//cout << *index << endl;
		return t_nRes;
	}
};
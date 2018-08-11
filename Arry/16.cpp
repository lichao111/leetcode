#include "../base.h"
/*
For example, given array S = {-1 2 1 -4}, and target = 1. 
							 {-4 -1 1 2}
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int t_nRet = 0;
		int t_nLen = nums.size();
		assert(t_nLen >= 3);
		sort(nums.begin(), nums.end());
		int t_nOldDis = abs(target - nums[0] - nums[1] - nums[t_nLen-1] );
		int t_nNewDis;
		for (vector<int>::iterator i = nums.begin(); i != nums.end() - 1; i++) {
			int t_ntarget = target - *i;
			vector<int>::iterator j = i + 1;
			vector<int>::iterator k = nums.end() - 1;

			while (j < k) {
				t_nNewDis = abs(*j + *k - t_ntarget);
				if (t_nNewDis <= t_nOldDis) {
					t_nRet = *i + *j + *k;
					t_nOldDis = t_nNewDis;
					cout << *i << " " << *j << " " << *k;
					cout << endl;
				}
				if (0 == *j + *k - t_ntarget)
					return target;
				else if (*j + *k - t_ntarget < 0) {
					j++;
				}
				else {
					k--;
				}
			}
		}
		return t_nRet;
	}

	void display(vector<int> s) {
		for (int i = 0; i < s.size(); i++) {
				cout << s[i] << " ";
			}
			cout << endl;
		}
};
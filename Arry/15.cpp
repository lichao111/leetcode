#include "../base.h"

/*
For example, given array S = [-1, 0, 1, 2, -1, -4],
							 [-4,-1, -1,0, 1, 2 ]
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]*/

class Solution {
public:
/*	vector<vector<int> > threeSum(vector<int>& nums) {//暴力 O(N^3)
		vector<vector<int> > t_vecRes;
		int t_nLen = nums.size();
		if (t_nLen < 3)
			return t_vecRes;
		vector<int> t_vecTmp;
		for (int i = 0; i < t_nLen - 2; i++) {
			for (int j = i+1; j < t_nLen - 1; j++) {
				for (int k = j+1; k < t_nLen; k++) {
					if (0 == (nums[i] + nums[j] + nums[k])) {
						t_vecTmp.clear();
						t_vecTmp.push_back(nums[i]);
						t_vecTmp.push_back(nums[j]);
						t_vecTmp.push_back(nums[k]);
						t_vecRes.push_back(t_vecTmp);
					}
				}
			}
		}
		//排序，去重
		for (int i = 0; i < t_vecRes.size(); i++) {
			sort(t_vecRes[i].begin(), t_vecRes[i].end());
		}
		sort(t_vecRes.begin(), t_vecRes.end());
		vector<vector<int> >::iterator it = unique(t_vecRes.begin(), t_vecRes.end());
		t_vecRes.erase( it,t_vecRes.end());
	}
*/
	vector<vector<int> > threeSum(vector<int>& nums,int target) {//O(n^2)
		vector<vector<int> > t_vecRes;
		int t_nLen = nums.size();
		if (t_nLen < 3)
		{
			return t_vecRes;
		}
		sort(nums.begin(), nums.end());
		vector<int> t_vecTmp;
		for (int i = 0; i < t_nLen;) {
			int t_nTarget = target - nums[i];//target sum, find two nums which sum is equal to this target
			int j = i + 1;//the index of the second number;
			int k = t_nLen - 1;//the index of the third number;
			while (j < k) {
			//	cout << i << " " << j << " " << k << " " << endl;

				if (nums[j] + nums[k] == t_nTarget) {
					t_vecTmp.clear();
					t_vecTmp.push_back(nums[i]);
					t_vecTmp.push_back(nums[j]);
					t_vecTmp.push_back(nums[k]);
					t_vecRes.push_back(t_vecTmp);
					while (j < k&& nums[j] == t_vecTmp[1]) j++;
					while (j < k&& nums[k] == t_vecTmp[2]) k--;
				}
				else if (nums[j] + nums[k] > t_nTarget) {
					k--;
				}
				else {
					j++;
				}

			}
			while (i < t_nLen&&nums[i] == (-t_nTarget)) i++;
		}
		return t_vecRes;
	}

	void display(vector<vector<int> > s) {
		cout << s.size() << endl;

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].size(); j++) {
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
	}
};
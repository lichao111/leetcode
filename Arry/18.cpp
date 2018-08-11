#include "../base.h"
/*For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
							   [-2,-1,0,0,1,2]
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > t_vecRes;
		vector<vector<int> > t_vectmp;
		vector<int> t_vecintcase;
		int t_nLen = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i < t_nLen - 3;) {
			int k = *nums.begin();
			nums.erase(nums.begin());
			t_vectmp.clear();

			t_vectmp = this->threeSum(nums, target - k);
		//	this->display(t_vectmp);
			if (!t_vectmp.empty()) {
				for (vector<vector<int> >::iterator it = t_vectmp.begin(); it != t_vectmp.end(); it++){
					t_vecintcase.clear();
					t_vecintcase.push_back(k);
					t_vecintcase.push_back((*it)[0]);
					t_vecintcase.push_back((*it)[1]);
					t_vecintcase.push_back((*it)[2]);
					t_vecRes.push_back(t_vecintcase);

				}
			}
			i++;
			while (*nums.begin() == k&&!nums.empty()) {
				cout << i << endl;
				cout << "--" << endl;
				if (!nums.empty())
					nums.erase(nums.begin());
				i++;
			}
		}
		//this->display(t_vecRes);
		return t_vecRes;
	}

	vector<vector<int> > threeSum(vector<int>& nums,int target) {
		vector<vector<int> > t_vecRes;
		int t_nLen = nums.size();
		if (t_nLen < 3)
		{
			return t_vecRes;
		}
		sort(nums.begin(), nums.end());
		vector<int> t_vecTmp;
		for (int i = 0; i < t_nLen;) {
		//	cout << "--------" << endl;
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
			while (i < t_nLen&&nums[i] == (target-t_nTarget)) i++;
		}
		return t_vecRes;
	}

public:
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
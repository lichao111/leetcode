#include "../base.h"

/*1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.empty()) return;// if empty
		for (vector<int>::iterator iter = nums.end()-1;; iter--) {
			vector<int> t_vecTmp(iter,nums.end());
			if (!this->ifsorted(t_vecTmp)) {//t_vecTmp前小后大
				//cout << "----" << endl;
				//Display(t_vecTmp);
				//cout << "---" << endl;
				for (vector<int>::iterator iter1 = iter; iter1 != nums.end(); iter1++) {
					if (iter1 == nums.end() - 1) {
						int k = *iter1;
						*iter1 = *iter;
						*iter = k;
						sort(iter + 1, nums.end());
						return;
					}
					if ((*iter1 > *iter) && (*(iter1+1) <= *(iter))) {
						int k = *iter1;
						*iter1 = *iter;
						*iter = k;
						sort(iter+1, nums.end());
						//Display(nums);
						return;
					}
					//if (iter == nums.begin()) return;
				}
			}
			if (iter == nums.begin()) { sort(nums.begin(), nums.end()); return; }
				//cout << "begin()" << endl;
		}
		
	}
	bool ifsorted(vector<int> p_vecseed) {//judge if the vector is bigger in first
		if (p_vecseed.empty()) return true;
		for (vector<int>::iterator iter = p_vecseed.begin()+1; iter != p_vecseed.end(); iter++) {
			if (*iter > *(iter - 1)) return false;
		}
		return true;
	}
};

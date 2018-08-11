#include "../base.h"

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> t_vecRes;
		int index;
		if ((index = this->BinarySearch(nums, target)) == -1) {
			 t_vecRes.push_back(-1);
			 t_vecRes.push_back(-1);
			 return t_vecRes;
		}
		int t_nEnd = index;
		int t_nStart=index;
		while (t_nStart >= 0) {
			if (nums[t_nStart] == target) {
				t_nStart--;
			}
			else
			{
				t_nStart++;
				break;
			}
		}
		t_vecRes.push_back(t_nStart == -1 ? 0:t_nStart);
		while (t_nEnd <= nums.size()-1) {
			if (nums[t_nEnd] == target) {
				t_nEnd++;
			}
			else
			{
				t_nEnd--;
				break;
			}
		}
		t_vecRes.push_back(t_nEnd == nums.size() ? nums.size()-1: t_nEnd);
		return t_vecRes;
	}

	int BinarySearch(vector<int> a, int p_nTarget) {
		int t_nRes = -1;
		int t_nLen = a.size();
		//if (t_nLen == 0) return t_nRes;
		int start = 0;
		int end = t_nLen - 1;
		int t_nBinary;
		for (; start <= end;) {
			t_nBinary = (end + start) / 2;
			if (a[t_nBinary] > p_nTarget) {
				end = t_nBinary - 1;
			}
			else if (a[t_nBinary] < p_nTarget) {
				start = t_nBinary + 1;
			}
			else {
				return t_nBinary;
			}
		}
		return -1;
	}





};

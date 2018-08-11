#include "../base.h"

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) { //O(log(m*n))
		string t_strRes = "";
		int t_nVecNum = strs.size();
		if (t_nVecNum == 0) return "";
		int t_nMinSize = strs[0].size();
		for (int i = 0; i < t_nVecNum; i++)
		{
			t_nMinSize = t_nMinSize > strs[i].size() ? strs[i].size() : t_nMinSize;
		}
		//char t_cTmp;
		for (int i = 0; i < t_nMinSize; i++) {
			char t_cTmp = strs[0][i];
			for (int j = 0; j < t_nVecNum; j++) {
				if (strs[j][i] == t_cTmp)
					continue;
				else
					return t_strRes;
			}
			t_strRes += t_cTmp;
		}
		return t_strRes;
	}
};

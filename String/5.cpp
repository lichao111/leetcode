#include "../base.h"

//Input: "babad"
//
//	Output : "bab"
//
//	Note : "aba" is also a valid answer.
//
//	Input : "cbbd"
//
//	Output : "bb"

class Solution {
public:
	string longestPalindrome(string s) {
		string t_strRes = "";
		string t_strTmp = "";
		bool t_bok = false;
		int t_nLen = s.size();
		for (int t_maxLen = t_nLen; t_maxLen >= 1; t_maxLen--)
		{
			for (int t_nStart = 0;t_nStart + t_maxLen <= t_nLen;t_nStart++)
			{
				if (ispalindrome(s.substr(t_nStart, t_maxLen)))
					return s.substr(t_nStart, t_maxLen);
			}
		}

		return t_strRes;
	}

private:
	bool ispalindrome(string p_str)
	{
		string::iterator iter1 = p_str.begin(); string::reverse_iterator  iter2 = p_str.rbegin();
		for (;
			iter1 != p_str.end() && iter2 !=p_str.rend(); iter1++, iter2++)
		{
			if (*iter1 != *iter2)
				return false;
		}
		return true;
	}
};
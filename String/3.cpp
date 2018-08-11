#include "../base.h"
/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


/*每次找到重复的串之后，下次检查从上次失败的字符的下一个位置开始


//c++ code in 9 lines, it is amazing

int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}

*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int t_nRes = 0;
		int t_nLen = s.size();
		do
		{
			if (t_nLen == 0)
				break;
			if (t_nLen == 1)
			{
				t_nRes = 1;
				break;
			}
			t_nRes = 1;
			int start= -1;
			for (int i = 0,j=i+1;i<t_nLen-1;)
			{
				//cout << start << endl;
				string t_strtmp = s.substr(i, j-i+1);
				//cout << t_strtmp << endl;
				if (isunique(t_strtmp,start))
				{
					cout << t_strtmp << endl;
					t_nRes = t_nRes < t_strtmp.size() ? t_strtmp.size() : t_nRes;
					j++;
				}
				else
				{
					assert(start != -1);
					i += start+1;  //在子串中的位置，换算到母串中，要加上i
					j++;
				}
				if (j== t_nLen)
				{
					break;
				}
				cout << i << "--" << j << endl;
				//cout << j << endl;
			}

		} while (false);
		return t_nRes;
	}
	bool isunique(string p_str,int &k)
	{
		k = -1;
		int t_nLen = p_str.size();
		if (t_nLen == 0||t_nLen ==1)
			return true;
		for (int i = 0, j = 1; i < t_nLen - 1;)
		{
			if (p_str[i] == p_str[j])
			{
				k = i;
				return false;
			}
			else
			{
				j++;
			}
			if (j == t_nLen)
			{
				i++;
				j = i + 1;
			}
		}
		return true;
	}
};
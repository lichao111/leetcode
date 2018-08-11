#include "../base.h"
/*Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
isMathc("ab",".*c") -> false ??????????????
没有弄明白到底是什么匹配规则  

---------------------------------------------------------------
匹配规则含混的点在于，*所代表的“零个前一字符”是指把前面一个字符消除掉
转换后的p要和S的长度相等
---------------------------------------------------------------
*/
class Solution
{
public:
	bool isMatch(string s, string p) {
		if (p == "") return s == "";
		if (s[0] == p[0])
			return isMatch(s.substr(1, s.size() - 1), p.substr(1, s.size() - 1));
		else if
		{

		}

		return true;
	}
	bool ismatch(string s, string p)
	{
		return Match(s, 0, p, 0);
	}
	bool Match(string s, int index1, string p, int index2) {
		if (index2 >= p.size())return index1 >= s.size();
		if (index2 + 1<p.size() && p[index2 + 1] == '*') {
			while (index1<s.size() && (p[index2] == '.' || p[index2] == s[index1])) {
				if (Match(s, index1, p, index2 + 2))return true;
				index1++;
			}
			return Match(s, index1, p, index2 + 2);
		}
		else if (index1<s.size() && (p[index2] == '.' || p[index2] == s[index1])) {
			return Match(s, index1 + 1, p, index2 + 1);
		}
		return false;
	}
};


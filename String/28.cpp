#include "../base.h"

/*Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1*/

class Solution {
public:
	int strStr(string haystack, string needle) {
		size_t t_nRes = haystack.find(needle);
		if (t_nRes == string::npos)
		{
		return -1;
	}
		else
			return t_nRes;
	}
};
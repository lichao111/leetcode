#include "../base.h"

/*1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count - and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.*/

class Solution {
public:
	string countAndSay(int n) {
		string t_nRes = "1";
		if (n == 1) return t_nRes;
		n--;
		while (n--)
		{
			t_nRes = this->read(t_nRes);
		}
		return t_nRes;
	}
	string read(string p_strseed) {
		string t_nRes = "";
		int t_nCount = 1;
		string::iterator iter = p_strseed.begin();
		char t_strNum = *iter ;
		for ( iter = p_strseed.begin()+1; iter != p_strseed.end(); iter++) {
			if (*iter ==t_strNum) {
				t_nCount++;
			}
			else {
				char a[12];
				sprintf(a, "%d", t_nCount);
				t_nRes+=(string(a));
				t_nRes+=(t_strNum);
				t_strNum = *iter;
				t_nCount = 1;
			}
		}
		char a[12];
		sprintf(a, "%d", t_nCount);
		t_nRes+=(string(a));
		t_nRes+=(t_strNum);
		return t_nRes;
	}
};
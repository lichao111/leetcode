#include "../base.h"
/*Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int t_nRes = 0;
		int t_nLen = s.size();
		vector<int> t_vecLeftNomate;
		stack<char> t_staLeft;
		size_t t_nTmp = s.find_first_of('(');
		if (t_nTmp != string::npos) {
			t_vecLeftNomate.push_back(t_nTmp);
			t_staLeft.push('(');
		}
		else {
			return 0;
		}
		for (size_t i = t_nTmp+1; i < s.size(); i++){
			if (s[i] == '(') {
				t_vecLeftNomate.push_back(i);
				t_staLeft.push('(');
			}
			else {//s[i]==')'
				if (t_staLeft.empty());
				else
				{
					t_staLeft.pop();
					t_vecLeftNomate.pop_back();
				}
			}
		}
		cout << "----------" << endl;
		Display(t_vecLeftNomate);
		cout << "--------------" << endl;
		int t_nTm = 0;
		int start, end;
		if (t_vecLeftNomate.size() == 0) {
			t_nRes = this->LengthOf(-1, t_nLen,s);
			return t_nRes;
		}
		t_nRes = this->LengthOf(-1, t_vecLeftNomate[0], s);
		for (int i = 0; i < t_vecLeftNomate.size()-1;i++ ) {
			int t = this->LengthOf(t_vecLeftNomate[i], t_vecLeftNomate[i+1], s);
			t_nRes = t > t_nRes ? t : t_nRes;
		}
		int t = this->LengthOf(t_vecLeftNomate[t_vecLeftNomate.size() - 1], t_nLen, s);
		t_nRes = t > t_nRes ? t : t_nRes;
		return t_nRes;
	}
	int LengthOf(size_t start, size_t end,string s) {
		if (start == end) return 0;
		int t_nRes = 0;
		string t_str = s.substr(start + 1, end - start-1);
		if (t_str.empty())  return t_nRes;
		stack<char> t_staLeft;
		int t_nTmp = 0;
		for (size_t i = 0; i < t_str.size(); i++) {
			if (t_str[i] == '(')
			{
				t_staLeft.push('(');
			}
			else {
				if (t_staLeft.empty()) {
					t_nRes = t_nRes > t_nTmp ? t_nRes : t_nTmp;
					t_nTmp = 0;
					continue;
				}
				else
				{
					t_staLeft.pop();
					t_nTmp += 2;
				}
			}
		}
		t_nRes = t_nRes > t_nTmp ? t_nRes : t_nTmp;

		return t_nRes;
	}
};

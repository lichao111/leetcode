#include "../base.h"

/*Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

For example, given n = 3, a solution set is :

[
	"((()))",
	"(()())",
	"(())()",
	"()(())",
	"()()()"
]*/

class Solution {//判断一个结果是否合法，只需从左往右数括号的个数，在任一位置，只要左括号数大于右括号数，这个结果就是合法的
public:
	vector<string> generateParenthesis(int n) {
		vector<string> t_vecRes;
		if (n == 0) return t_vecRes;

		
	}
	vector<string> GenerateParenthesis(int n) {
		vector<string> res;
		addingpar(res, "", n, 0);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m) {
		cout << n << " " << m;
		cout << str << endl;
		cout << "--" << endl;
		if (n == 0 && m == 0) {
			v.push_back(str);
			return;
		}
		if (m > 0) { addingpar(v, str + ")", n, m - 1); }
		if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
	}
};
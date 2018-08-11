#include "../base.h"

/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
([)]
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> Left;
		
		//构造1个栈
		for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
			if (*iter == '(' || *iter == '{' || *iter == '[') {
				Left.push(*iter);
			}
			else if(*iter == ')' || *iter == '}' || *iter == ']') {
				if (Left.empty())
					return false;
				if (*iter == ')') {
					if (Left.top() != '(') return false;
					else Left.pop();
				}
				else if (*iter == '}') {
					if (Left.top() != '{') return false;
					else Left.pop();
				}
				else if (*iter == ']') {
					if (Left.top() != '[') return false;
					else Left.pop();
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		if (Left.empty()) return true;
		else return false;
	}
};
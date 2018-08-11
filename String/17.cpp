#include "../base.h"

/*Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> t_vecRes;
		if (digits.empty())
			return t_vecRes;
		map<char, string> t_mapPhone;
		t_vecRes.push_back("");
		t_mapPhone.insert(pair<char, string>('2', "abc"));
		t_mapPhone.insert(pair<char, string>('3', "def"));
		t_mapPhone.insert(pair<char, string>('4', "ghi"));
		t_mapPhone.insert(pair<char, string>('5', "jkl"));
		t_mapPhone.insert(pair<char, string>('6', "mno"));
		t_mapPhone.insert(pair<char, string>('7', "pqrs"));
		t_mapPhone.insert(pair<char, string>('8', "tuv"));
		t_mapPhone.insert(pair<char, string>('9', "wxyz"));
		vector<string> t_vecTmp;
		string t_strCase;
		for (string::iterator iter = digits.begin(); iter != digits.end(); iter++) {
			map<char, string>::iterator it = t_mapPhone.find(*iter);
			if (it != t_mapPhone.end()) {
				t_strCase = it->second;
				t_vecTmp.push_back(t_strCase);
			}
		}
		int t_nLen = t_vecTmp.size();
		for (int i = 0; i < t_nLen; i++)
		{
			this->display(t_vecRes);
			t_vecRes = this->AddCase(t_vecRes, t_vecTmp[i]);
		//	getchar();
		}
		this->display(t_vecRes);
		return t_vecRes;
	}

	vector<string> AddCase(vector<string> init, string s) {
		vector<string> t_vecRes;
		for (vector<string>::iterator iter1 = init.begin(); iter1 != init.end(); iter1++) {
			for (string::iterator iter2 = s.begin(); iter2 != s.end(); iter2++){
				//cout << *iter1 << endl;
				string t_strtmp = *iter1;
				t_strtmp += *iter2;
				//cout << "--" << t_strtmp << endl;;
				t_vecRes.push_back(t_strtmp);
			}
		}
		return t_vecRes;
	}
	void display(vector<string> s) {
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << endl;
	}
};

#include "../base.h"

/*s: "barfoothefoobarman"
	words : ["foo", "bar"]

	You should return the indices : [0, 9].
	(order does not matter).*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> t_vecRes;
		if (words.empty())
			return t_vecRes;
		int t_nOneWordLen = words[0].size();// the length of one word in words
		int t_nTotalLen = t_nOneWordLen * words.size();//the length of the total words in words
		int t_nStart = 0;
		while (t_nStart < s.size()) {
			cout << "t_nStart:" << t_nStart << endl;
			int t_nTmp = find_first_words(s, t_nStart, words);
			//cout << t_nTmp << endl;
			if (t_nTmp >= t_nStart&&t_nTmp < s.size())//found
			{
				string t_strTmp = s.substr(t_nTmp, t_nTotalLen);
				cout << t_strTmp << endl;
				if (t_strTmp.size() != t_nTotalLen)// not enough char in s, over
					return t_vecRes;
				else {
					cout << this->Equal(t_strTmp, words) << endl;
					if (this->Equal(t_strTmp, words)) {
						cout << "push_back" << t_nTmp << endl;
						t_vecRes.push_back(t_nTmp);
					}
					else {
						t_nStart=t_nTmp+1;
						continue;
					}
				}
				t_nStart=t_nTmp+1;
			}
			else {//not found
				return t_vecRes;
			}
		}
		return t_vecRes;
	}
	int find_first_words(string s, int start,vector<string> words) {
		if (s.size() < start) {
			return -2;
		}
		string t_strTmp = s.substr(start);
		std::size_t t_iterRes = t_strTmp.find(words[0]);
		if (t_iterRes == 0) {
			return t_iterRes+start;
		}
		int WordsNum = words.size();
		int i = 0;
		while (++i<WordsNum)
		{
			std::size_t onePositon = t_strTmp.find(words[i]);
			if (onePositon !=string::npos) {//found
				t_iterRes = t_iterRes < onePositon ? t_iterRes : onePositon;
				if (t_iterRes == 0) {
					return t_iterRes+start;
				}
			}
		}
		return  t_iterRes+start;
	}
	bool Equal(string s1, vector<string> words) {
		if (words.empty()) return s1.empty();
		int t_nTotal = s1.size();
		int t_nOneWordLen = words[0].size();
		vector<string> t_vecTmp;
		int t_nStart = 0;
		for (int i = 0; i < words.size(); i++)
		{
			t_vecTmp.push_back(s1.substr(t_nStart, t_nOneWordLen));
			t_nStart += t_nOneWordLen;
		}
		sort(t_vecTmp.begin(), t_vecTmp.end());
		sort(words.begin(), words.end());
		if (t_vecTmp == words)
			return 1;
		else
			return 0;
	}

};
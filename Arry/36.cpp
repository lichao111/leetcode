#include "../base.h"

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		//row
		for (int i = 0; i < 9; i++)
		{
			if (!this->CheckNineNode(board[i]))
				return false;
		}
		//column
		for (int i = 0; i < 9; i++) {
			vector<char> t_vecTmp;
			for (int j = 0; j < 9; j++) {
				t_vecTmp.push_back(board[j][i]);
			}
			if (!this->CheckNineNode(t_vecTmp)) {
				return false;
			}
		}
		//partily
		for (int i = 0; i < 9;i+=3 ) {
			vector<char> t_vecTmp;
			for (int j = 0; j < 3; j++) {
				t_vecTmp.push_back(board[j][i]);
				t_vecTmp.push_back(board[j][i+1]);
				t_vecTmp.push_back(board[j][i+2]);
			}
			if (!this->CheckNineNode(t_vecTmp)) {
				return false;
			}
			t_vecTmp.clear();
			for (int j = 3; j < 6; j++) {
				t_vecTmp.push_back(board[j][i]);
				t_vecTmp.push_back(board[j][i + 1]);
				t_vecTmp.push_back(board[j][i + 2]);
			}
			if (!this->CheckNineNode(t_vecTmp)) {
				return false;
			}
			t_vecTmp.clear();
			for (int j = 6; j < 9; j++) {
				t_vecTmp.push_back(board[j][i]);
				t_vecTmp.push_back(board[j][i + 1]);
				t_vecTmp.push_back(board[j][i + 2]);
			}
			if (!this->CheckNineNode(t_vecTmp)) {
				return false;
			}
		}
		return true;

	}
	bool CheckNineNode(vector<char> p_vec) {
		assert(p_vec.size() == 9);
		vector<char> t_vecTmp;
		for (int i = 0; i < 9; i++) {
			if (p_vec[i] == '.') {
				continue;
			}
			else if(p_vec[i]>='0'&&p_vec[i]<='9'){
				t_vecTmp.push_back(p_vec[i]);
			}
			else{
				assert(1);
			}
		}
		int t_nBefore = t_vecTmp.size();
		sort(t_vecTmp.begin(), t_vecTmp.end());
		unique(t_vecTmp.begin(), t_vecTmp.end());
		t_vecTmp.erase(unique(t_vecTmp.begin(), t_vecTmp.end()), t_vecTmp.end());
		int t_nAfter = t_vecTmp.size();
		if (t_nBefore == t_nAfter) return true;
		else return false;
	}
};

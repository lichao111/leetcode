#include "../base.h"

/*Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
  ]*/
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > t_vecRes;
		sort(candidates.begin(), candidates.end());
		vector<int> t_vecAtom;
		for (int i = 0; i < candidates.size();i++) {
			cout << "??????" << i << endl;
			BackTracking(candidates, t_vecRes, t_vecAtom, target, i); 
		}
		return t_vecRes;
	}
	void BackTracking(vector<int> candiadates,vector<vector<int> > &t_vecRes, vector<int> &t_vecAtom,int target, int i){
		cout << candiadates[i]<<':'<<target << endl;
		Display(t_vecAtom);
		if (candiadates.size() == i) {
			t_vecAtom.clear();
			return;
		}
		if (candiadates[i] < target) {
			t_vecAtom.push_back(candiadates[i]);
			BackTracking(candiadates, t_vecRes, t_vecAtom, target-candiadates[i], i);

		}
		else if(candiadates[i]>target)
		{	
			if (t_vecAtom.empty()) {
				BackTracking(candiadates, t_vecRes, t_vecAtom, target + candiadates[i], i + 1);
			}
			else
			{
				t_vecAtom.pop_back();
				BackTracking(candiadates, t_vecRes, t_vecAtom, target+candiadates[i], i+1);
			}
		}
		else//candiadates[i]==target
		{
			cout << "------------------" << endl;
			t_vecAtom.push_back(candiadates[i]);
			t_vecRes.push_back(t_vecAtom);
			//Display(t_vecAtom);
			//cout << t_vecRes.size() << endl;
			//DisplayVecofVec(t_vecRes);
			t_vecAtom.clear();
			DisplayVecofVec(t_vecRes);
			cout << "---" << endl;
			return;
			//BackTracking(candiadates, t_vecRes, t_vecAtom,  forevertarget, i + 1);
		}
	}
	std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
	std::sort(candidates.begin(), candidates.end());
	std::vector<std::vector<int> > res;
	std::vector<int> combination;
	combinationSum2(candidates, target, res, combination, 0);
	return res;
}
private:
	void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
			if (i == begin || candidates[i] != candidates[i - 1]) {
				combination.push_back(candidates[i]);
				combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
				combination.pop_back();
			}
	}
public:
	std::vector<std::vector<int> > combinationSum1(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
			combination.push_back(candidates[i]);
			Display(combination);
			combinationSum(candidates, target - candidates[i], res, combination, ++i);
			combination.pop_back();
		}
	}

};

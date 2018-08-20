#include "../base.h"
#include <numeric>

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
	vector<vector<int> > combinationSum1(vector<int>& candidates, int target) {
		vector<vector<int> > t_vecRet;
		if(candidates.empty()) return t_vecRet;
		sort(candidates.begin(),candidates.end());
		int t_nLen = candidates.size();
		vector<int> t_vecIter;
		int i=0;
		int j =0;
		int t_nSum=0; 
		t_vecIter.push_back(candidates[0]);
		if(candidates[0]==target)
		{
			t_vecRet.push_back(t_vecIter);
			return t_vecRet;
		}
		else if(candidates[0]>target)
		{
			return t_vecRet;
		}
		map<int,int> t_mapRecord;
		for(int i = 0;i<t_nLen;i++)
		{
			t_mapRecord[candidates[i]] = i;
		}
		do{
			t_nSum = accumulate(t_vecIter.begin(),t_vecIter.end(),0);
			if(t_nSum<target)
			{
				t_vecIter.push_back(candidates[j]);
				continue;
			}
			else{
				if(t_nSum == target)
				{
					t_vecRet.push_back(t_vecIter);
				}
				t_vecIter.pop_back();
				while(true)
				{
					if(t_vecIter.empty())
					{
				
							return t_vecRet;
						
					}
					int k = *(t_vecIter.end()-1);
					int iter = t_mapRecord[k];
					iter++;
					j = iter;
					if(j>=t_nLen)
					{
						t_vecIter.pop_back();
						continue;
					}
					else{
						t_vecIter.pop_back();
						t_vecIter.push_back(candidates[j]);
						break;
					}
				}
			}
		}while(true);
		return t_vecRet;
	}

	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {//backtrack method of recursion 递归方式的回溯效率要差与非第归方式的回溯
		vector< vector<int> > t_nRet; 
		vector<int> t_vectmp;
		sort(candidates.begin(),candidates.end());
		backtrack(candidates,target,t_vectmp,0,t_nRet);
		return t_nRet;
	}
private:
	void backtrack(vector<int> &candidates,int target,vector<int> tmp,int index ,vector<vector<int> > &t_nRet){
		//the return condition
		if(0==target){
			t_nRet.push_back(tmp);
			return;
		}
		for(int i = index;i<candidates.size();i++)
		{
			if(candidates[i]>target){
				return;
			}
			tmp.push_back(candidates[i]);
			Display(tmp);
			cout<<target<<endl;
			cout<<"i "<<i<<endl;
			backtrack(candidates,target-candidates[i],tmp,i,t_nRet); //运行此backtrack函数前后的tmp是没有变化的
			tmp.pop_back();
		}
	}
};

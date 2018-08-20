#include "../base.h"
#include <numeric>
class Solution {
public:
	vector<vector<int> > combinationSum1(vector<int>& candidates, int target) {
        vector<vector<int> > t_vecRet;
		if(candidates.empty()) return t_vecRet;
		sort(candidates.begin(),candidates.end());
		//Display(candidates);
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
		map<int,int> t_mapCount;
		for(int i = 0;i<t_nLen;i++)
		{
			//t_mapRecord[candidates[i]] = i;
			t_mapCount[candidates[i]]++;
			//Displaymap(t_mapCount);
		}
		map<int,int> t_mapCountIter;
		t_mapCountIter[candidates[j]]++;
		vector<int>::iterator it = unique(candidates.begin(),candidates.end());
		candidates.resize(distance(candidates.begin(),it));
		t_nLen = candidates.size();
		//Display(candidates);
		for(int i = 0;i<t_nLen;i++)
		{
			t_mapRecord[candidates[i]] = i;
			//t_mapCount[candidates[i]]++;
		}
		bool kk =false;
		do{
			t_nSum = accumulate(t_vecIter.begin(),t_vecIter.end(),0);
			//Display(t_vecIter);
			if(t_nSum<target)
			{
				if(t_mapCount[candidates[j]]==t_mapCountIter[candidates[j]])
				{
					//cout<<"====================="<<endl;
					j++;
					if(j>=t_nLen)  kk = true;

				}
                if(!kk)
                {
				t_vecIter.push_back(candidates[j]);
				t_mapCountIter[candidates[j]]++;
				//cout<<"-----"<<t_mapCount[candidates[j]]<<endl;
				//cout<<t_mapCountIter[candidates[j]]<<endl;
				continue;
                }
			}
			if(t_nSum>=target||kk){
                kk = false;
				if(t_nSum == target)
				{
					t_vecRet.push_back(t_vecIter);
				}
				int tmp = t_vecIter.back();
				t_vecIter.pop_back();
				t_mapCountIter[tmp]--;
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
						int tmp = t_vecIter.back();
						 t_vecIter.pop_back();
						t_mapCountIter[tmp]--;
						continue;
					}
					else{
						int tmp = t_vecIter.back();
						t_mapCountIter[tmp]--;
						t_vecIter.pop_back();
						t_vecIter.push_back(candidates[j]);
						t_mapCountIter[candidates[j]]++;
						//cout<<candidates[j]<<endl;
						//Displaymap(t_mapCountIter);
						break;
					}
				}
			}
		}while(true);
		return t_vecRet;
    }
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		
		vector< vector<int> > t_nRet;
		vector<int> tmp;
		for(auto i:candidates){
			t_mapCount[i]++;
		}
		candidates.resize(distance(candidates.begin(),unique(candidates.begin(),candidates.end())));
		Displaymap(t_mapCount);
		t_nRet.clear();
		tmp.clear();
		backtrack(candidates,target,tmp,t_nRet,0);
	}
private:
	void backtrack(vector<int> &candidates,int target,vector<int> &tmp,vector<vector<int> > &t_vecRet,int index){
		if(target==0){
			t_vecRet.push_back(tmp);
			return ;
		}
		for(int i= index;i<candidates.size();i++){
			if(candidates[i]>target){
				return;
			}
			tmp.push_back(candidates[i]);
			t_mapCountTmp[candidates[i]]++;
			if(t_mapCount[candidates[i]]<t_mapCountTmp[candidates[i]])
			{
				tmp.pop_back();
			t_mapCountTmp[candidates[i]]--;
			return;
			}
			Display(tmp);
			cout<<target<<endl;
			backtrack(candidates,target-candidates[i],tmp,t_vecRet,i);
			tmp.pop_back();
			t_mapCountTmp[candidates[i]]--;
		}
	}
private:
	map<int,int> t_mapCount;
	map<int,int> t_mapCountTmp;
};


#include "../base.h"
/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > t_vecRet;
        vector<int> t_vecTmp;
    
        this->backtrack(t_vecRet,t_vecTmp,1,n,k);
      
        return t_vecRet;
    }

private:
    void backtrack(vector<vector<int> >& t_vecRet,vector<int> &t_vecTmp,int index,const int &n,const int &k){
        if(t_vecTmp.size()==k){
            t_vecRet.push_back(t_vecTmp);
            return ;
        }
        for(int i=index;i<=n;i++){
            t_vecTmp.push_back(i);
            backtrack(t_vecRet,t_vecTmp,i+1,n,k);
            t_vecTmp.pop_back();
        }
    }
    
};
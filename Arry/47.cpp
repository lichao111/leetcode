#include "../base.h"

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > t_vecRet;
        int t_nLen = nums.size();
        for(int i = 0;i<t_nLen;i++)
        {
            t_vecRet = insertnum(nums[i],t_vecRet);
          //  DisplayVecofVec(t_vecRet);
        } 
        sort(t_vecRet.begin(),t_vecRet.end());
        vector<vector<int> >::iterator it = std::unique (t_vecRet.begin(), t_vecRet.end());   // 10 20 30 20 10 ?  
         t_vecRet.resize( std::distance(t_vecRet.begin(),it) ); 
        return t_vecRet;   
    }
    vector<vector<int> > insertnum(const int &item,vector<vector<int> > t_vecRet)
    {
        vector<vector<int> > t_vecRetTmp;
        vector<int> t_vecTuple;
        int t_nLen = t_vecRet.size();
        int t_nRecord;
        if(t_nLen==0)
        {
            t_vecTuple.push_back(item);
            t_vecRetTmp.push_back(t_vecTuple);
            return t_vecRetTmp;
        }
        for(int i = 0;i<t_nLen;i++)
        {
            for(int j = 0;j<=t_vecRet[i].size();)
            {
                t_vecTuple = t_vecRet[i];
               // Display(t_vecTuple);
                t_vecTuple.insert(t_vecTuple.begin()+j,item);
                t_vecRetTmp.push_back(t_vecTuple);
                t_nRecord = t_vecRet[i][j];
                j++;
                while(item==t_vecRet[i][j-1])
                {
                    j++;
                }
            }
        }
        return t_vecRetTmp;
    }
};
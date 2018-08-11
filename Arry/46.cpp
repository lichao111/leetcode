#include "../base.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > t_vecRet;
        int t_nLen = nums.size();
        for(int i = 0;i<t_nLen;i++)
        {
            t_vecRet = insertnum(nums[i],t_vecRet);
          //  DisplayVecofVec(t_vecRet);
        }   
        return t_vecRet;   
    }
    vector<vector<int> > insertnum(const int &item,vector<vector<int> > t_vecRet)
    {
        vector<vector<int> > t_vecRetTmp;
        vector<int> t_vecTuple;
        int t_nLen = t_vecRet.size();
        if(t_nLen==0)
        {
            t_vecTuple.push_back(item);
            t_vecRetTmp.push_back(t_vecTuple);
            return t_vecRetTmp;
        }
        for(int i = 0;i<t_nLen;i++)
        {
            for(int j = 0;j<=t_vecRet[i].size();j++)
            {
                t_vecTuple = t_vecRet[i];
               // Display(t_vecTuple);
                t_vecTuple.insert(t_vecTuple.begin()+j,item);
                t_vecRetTmp.push_back(t_vecTuple);
            }
        }
        

        return t_vecRetTmp;
    }
};
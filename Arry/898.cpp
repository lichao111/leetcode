#include "../base.h"

/*
Input: [1,1,2]
Output: 3
Explanation: 
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: [1,2,4]
Output: 6
Explanation: 
The possible results are 1, 2, 3, 4, 6, and 7.
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {// 把vector换成set后速度有显著提升。只需要来的一般，不在需要去重
        set<int> t_vecRet;
        //vector<int> t_vecBox;
        for(int i = 0;i<A.size();i++){
            int t_mTmp = A[i];
            for(int j = i;j<A.size();j++){
                t_vecRet.insert(A[j]|t_mTmp);
                t_mTmp = A[j]|t_mTmp;
            }
        }
        //Display(t_vecRet);
        return t_vecRet.size();
    }
private:
    int GetBit(vector<int> &A){
        int t_nRet=0;
        for(int i = 0;i<A.size();i++){
            t_nRet = t_nRet|A[i];
        }
        return t_nRet;
    }
};
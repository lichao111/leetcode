#include "../base.h"
#include <numeric>
/*
Input: A = [1,1], B = [2,2]
Output: [1,2]
 
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int t_nSumA = accumulate(A.begin(),A.end(),0);
        int t_nSumB = accumulate(B.begin(),B.end(),0);
        int t_nDis = t_nSumB-t_nSumA;
        vector<int> t_nRet;
        for(int i = 0;i<A.size();i++)
        {
            for(int j =0;j<B.size();j++)
            {
                if(2*(B[j]-A[i])==t_nDis)
                {
                    t_nRet.push_back(A[i]);
                    t_nRet.push_back(B[j]);
                    return t_nRet;
                }
            }
        }
        return t_nRet;
    }
};
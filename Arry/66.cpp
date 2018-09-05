#include "../base.h"

/*
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> t_vecRet;
        int t_ntmp = 1;
        for(int i = digits.size()-1;i>=0;i--){
            t_vecRet.insert(t_vecRet.begin(),(digits[i]+t_ntmp)%10);
            t_ntmp = (digits[i]+t_ntmp)/10;
        }
        if(t_ntmp!=0){
            t_vecRet.insert(t_vecRet.begin(),t_ntmp);
        }
        return t_vecRet;
    }
};
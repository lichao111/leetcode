#include "../base.h"

/*
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//O(N^2) this way is too slow althought passed. Find a better algrithm!
        int t_nMax=nums[0];
        int t_nSum=0;
        
        for(int i = 0;i<nums.size();i++)
        {
            t_nSum=0;
            for(int j = i;j<nums.size();j++)
            {
                t_nSum += nums[j];
                t_nMax = max(t_nSum,t_nMax);
            }
        }
        return t_nMax;
    }
};
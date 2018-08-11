#include "../base.h"

/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int t_nJump = 0;
        int t_nMax = 0;
        if(nums.size()==1||nums.size()==0) return 0;
        for(int i = 0;i<nums.size();)
        {
        
            if(i+nums[i]>t_nMax)
            {
                t_nJump++;
                t_nMax = i+nums[i];
                if(t_nMax>=nums.size()-1)
                {
                    return t_nJump;
                }
            }
            int t_nMaxTmp = 0;
            for(int j = i+1;j<=i+nums[i];j++)
            { 
                t_nMaxTmp = (j+nums[j])>t_nMaxTmp?j+nums[j]:t_nMaxTmp;
            }
            if(t_nMaxTmp>t_nMax)
            {
                t_nJump++;
                t_nMax = t_nMaxTmp;
                if(t_nMax>=(nums.size()-1)) return t_nJump;
            }

            cout<<t_nMax<<"--"<<t_nJump<<endl;
            i = i+nums[i];
            while(nums[i]==0)
            {
                i++;
            }

            
        }
        return  t_nJump;

    }

};

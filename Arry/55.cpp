#include "../base.h"
/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
jump length is 0, which makes it impossible to reach the last index.*/

class Solution
{
  public:
    bool canJump_tmp(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        int t_nMaxStep = 0;
        vector<int> t_veczeroLocate;
        for (int i = 0; i < nums.size(); i++)
        {
            if (0 == nums[i])
            {
                t_veczeroLocate.push_back(i);
            }
        }
        if (t_veczeroLocate.empty())
            return true;
        int i = 0;
        //Display(t_veczeroLocate);
        bool ok = false;
        for (int j = 0; j < t_veczeroLocate.size();)
        {
            if (j == 0)
            {
                i = 0;
            }
            else
            {
                i = t_veczeroLocate[j - 1] + 1;
            }
            for (; i < t_veczeroLocate[j]; i++)
            {
                t_nMaxStep = i + nums[i] > t_nMaxStep ? i + nums[i] : t_nMaxStep;
                // cout<<"i "<<i<<endl;
                // cout<<"t_nMaxStep "<<t_nMaxStep<<endl;
                if (t_nMaxStep >= nums.size() - 1)
                    return true;
                if (t_nMaxStep > t_veczeroLocate[j])
                {
                    ok = true;
                    //break;
                }
            }
            //cout<<"ok "<<ok<<endl;
            if (ok == false)
                return false;
            ok = false;
            while (t_veczeroLocate[j] < t_nMaxStep)
            {
                j++;
            }
        }
        return true;
    }
    bool canJump(vector<int> &nums)// the better way
    {
        int t_nMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            t_nMax = max(t_nMax,i+nums[i]);
            if(t_nMax>=nums.size()-1) return true;
            if(t_nMax == i && nums[i]==0){
                return false;
            }
        }
        return true;
    }
};

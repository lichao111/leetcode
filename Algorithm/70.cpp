#include "../base.h"
/*
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int t_n1 = 2;
        int t_n2 = 1;
        int t_tmp = 0;
        for(int i = 3;i<=n;i++){
            t_tmp = t_n1;
            t_n1 = t_n1+t_n2;
            t_n2 = t_tmp;
            cout<<t_n1<<endl;
        }
        return t_n1;
    }
};
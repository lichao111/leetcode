#include "../base.h"
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class Solution
{
  public:
    int minDistance(string word1, string word2)//DP O(n)
    {
        int t_nlen1 = word1.size();
        int t_nlen2 = word2.size();
        if (t_nlen1 == 0 || t_nlen2 == 0)
        {
            return t_nlen1 + t_nlen2;
        }
        vector<int> t_Dis(t_nlen2+1, 0);
        for (int i = 0; i <= t_nlen2; ++i)
        {
            t_Dis[i] = i;
        }
        int tmp  = 0;
        int tmp1 = 1;
        //Display(t_Dis);
        for (int i = 1; i <= t_nlen1; i++)
        {
            
            tmp = t_Dis[0];
            t_Dis[0]=i;
            for(int j = 1;j<=t_nlen2;j++){
                tmp1 = t_Dis[j];
                if(word1[i-1]==word2[j-1])
                    t_Dis[j] = tmp;
                else{
                    t_Dis[j]= min(t_Dis[j],min(t_Dis[j-1],tmp))+1;
                }
                tmp = tmp1;
            }
           // Display(t_Dis);
        }
        return t_Dis[t_nlen2];
    }
};
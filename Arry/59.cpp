#include "../base.h"

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        int t_nMatrix[n][n];
        int i = 0, j = 0;
        int index = 1;
        int k = 0;
        vector<int> t_vecTmp;
        vector<vector<int>> t_vecRet;
        if (n == 0)
        {
            return t_vecRet;
        }
        if (n == 1)
        {
            t_vecTmp.push_back(1);
            t_vecRet.push_back(t_vecTmp);
            return t_vecRet;
        }
        bool over = false;
        do
        {
            for (; j < n-k; j++)
            {
                t_nMatrix[i][j] = index++;
                if ((index - 1) == n * n)
                {
                    over = true;
                    break;
                }    
            }
            if(over) break;
            j--;
            i++;
            for (; i < n-k; i++)
            {
                t_nMatrix[i][j] = index++;
                if ((index - 1) == n * n)
                 {
                    over = true;
                    break;
                }  
            }
            if(over) break;
            j--;

            i--;
            for (; j >= k; j--)
            {
                t_nMatrix[i][j] = index++;
                if ((index - 1) == n * n)
                {
                    over = true;
                    break;
                }  
            }
            if(over) break;
            i--;
            j++;
            for (; i > k; i--)
            {
                t_nMatrix[i][j] = index++;
                if ((index - 1) == n * n)
                {
                    over = true;
                    break;
                }  
            }
            if(over) break;
            j++;
            i++;
            k++;
        } while (1);
        for (int l = 0; l < n; l++)
        {
            for (int ll = 0; ll < n; ll++)
            {
                t_vecTmp.push_back(t_nMatrix[l][ll]);
            }
            t_vecRet.push_back(t_vecTmp);
            t_vecTmp.clear();
        }
        return t_vecRet;
    }
};

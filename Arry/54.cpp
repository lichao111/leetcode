#include "../base.h"

/*
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> t_nRet;
        if(matrix.empty()) return t_nRet;
        int column= matrix[0].size();
        int row = matrix.size();
        int t_niter = column*row;
        int i = 0;
        int j = 0;
        int k = 0;
        while(true)
        {
            while(j<column)
            {
                t_nRet.push_back(matrix[i][j++]);
                if(t_nRet.size()==t_niter) return t_nRet;
            }
            j--;
            i++;
            while(i<row)
            {
                t_nRet.push_back(matrix[i++][j]);
                if(t_nRet.size()==t_niter) return t_nRet;
            }
            i--;
            j--;
            while(j>=k)
            {
                t_nRet.push_back(matrix[i][j--]);
                if(t_nRet.size()==t_niter) return t_nRet;
            }
            j++;
            i--;
            while(i>k)
            {
                t_nRet.push_back(matrix[i--][j]);
                if(t_nRet.size()==t_niter) return t_nRet;
            }
            i++;
            j++;
            k++;
            row--;
            column--;
            //Display(t_nRet);
        }
        return t_nRet;
    }
};
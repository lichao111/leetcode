#include "../base.h"
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {//O(N^2)
        vector<vector<int> > matrix_dup = matrix;
        //DisplayVecofVec(matrix_dup);
        int n = matrix_dup.size()-1;
       //double core = (n+1.0)/2.0-1.0;
        pair<int,int> my_pair;
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                my_pair = Myfun(i,j,n);
                matrix[my_pair.first][my_pair.second] = matrix_dup[i][j];
            }
        }
    }
    pair<int,int> Myfun(int i,int j,const int &n)
    {
        pair<int,int> a;
        a.second = n - i;
        a.first = j;
       // cout<<'<'<<i<<','<<j<<'>'<<"   "<<'<'<<a.first<<','<<a.second<<'>'<<endl;
        return a;
    }
};
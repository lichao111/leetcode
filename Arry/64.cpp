#include "../base.h"

/*
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.size()==0) return 0;
        int t_nSize1 = grid.size();
        int t_nSize2 = grid[0].size();
        int a[t_nSize1][t_nSize2];
        a[0][0]=grid[0][0];
        for(int i=1;i<t_nSize1;i++){
            a[i][0]=grid[i][0]+a[i-1][0];
        }
        for(int i = 0;i<t_nSize2;i++){
             a[0][i]=grid[0][i]+a[0][i-1]; 
        }
        for(int i = 1;i<t_nSize1;++i){
            for(int j = 1;j<t_nSize2;++j){
                a[i][j]=min(a[i-1][j],a[i][j-1])+grid[i][j];
   
                cout<<a[i][j]<<endl;
                cout<<a[j][i]<<endl;
            }
        }
        return a[t_nSize1-1][t_nSize2-1];
    }
};
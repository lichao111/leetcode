#include "../base.h"

/*
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();    
        int count[m][n];
        //bool ok = true;
        for(int i=0;i<m;i++)
        {
            count[i][0] = 1;
        }
        for(int i = 0;i<n;i++)
        {
            count[0][i] = 1;
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++)
            {
                if(1!=obstacleGrid[i][j-1])
                {
                    count[i][j] =0 +  count[i][j-1];
                }
                if(1!=obstacleGrid[i-1][j])
                count[i][j] +=  count[i-1][j];
                cout<<i<<" "<<j<<" "<<count[i][j]<<endl;
            }
        }
        return count[m-1][n-1];
    }
};
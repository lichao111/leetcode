#include "../base.h"

/*
Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
*/
class Solution {
public:
    int surfaceArea(vector<vector<int> >& grid) {
        int t_nRet=0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]!=0)
                t_nRet += (4*grid[i][j]+2);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(j!=grid[i].size()-1)
                t_nRet -= 2*min(grid[i][j],grid[i][j+1]);
                if(i!=grid.size()-1)
                t_nRet -= 2*min(grid[i][j],grid[i+1][j]);
            }
        }
        
        return t_nRet;
    }
};
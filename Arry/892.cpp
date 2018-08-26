#include "../base.h"

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int t_nRet=0;
        for(auto i : grid){//shang
            for( auto j: i){
                if(j!=0){
                    t_nRet ++;
                }
            }
        }
        t_nRet *= 2;//xia
        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid.size();j++){
                if(i==0){
                    t_nRet += grid[i][j];
                }
                else{
                    t_nRet += ((grid[i][j]-grid[0][j])>0?(grid[i][j]-grid[0][j]):0);
                }
            }
        }
        int t_nLen = grid.size()-1;
        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid.size();j++){
                if(i==t_nLen){
                    t_nRet += grid[i][j];
                }
                else{
                    t_nRet += ((grid[i][j]-grid[t_nLen][j])>0?(grid[i][j]-grid[t_nLen][j]):0);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                if(j==0){
                    t_nRet += grid[i][j];
                }
                else{
                    t_nRet += ((grid[i][j]-grid[i][0])>0?(grid[i][j]-grid[i][0]):0);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                if(j==t_nLen){
                    t_nRet += grid[i][j];
                }
                else{
                    t_nRet += ((grid[i][j]-grid[i][t_nLen])>0?(grid[i][j]-grid[i][t_nLen]):0);
                }
            }
        }

        
        return t_nRet;
    }
};
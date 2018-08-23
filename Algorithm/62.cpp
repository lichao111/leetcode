#include "../base.h"

class Solution {
public:
    int uniquePaths2(int m, int n) {
        int t_nRet=0;
        pair<int,int> Locate;
        Locate.first = 0;
        Locate.second = 0;
        backtrack(t_nRet,Locate,m,n);
        return t_nRet;
    }


    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int> > path(m,vector<int>(n,0));
        for (int i = 0; i < m; i++)
            path[i][0] = 1;
        for (int i = 0; i < n; i++)
            path[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }

private:
    void backtrack(int &t_nRet,pair<int,int> Locate,const int &m,const int &n){
       // cout<<Locate.first<<" "<<Locate.second<<endl;
        if(Locate.first >= m || Locate.second>=n){
            return;
        }
        if(Locate.first == (m-1) || Locate.second==(n-1)){
            t_nRet ++;
            return;
        }
        Locate.first++;
        backtrack(t_nRet,Locate,m,n);
        Locate.first--;
        Locate.second++;
        backtrack(t_nRet,Locate,m,n);
        Locate.second--;
    }
};
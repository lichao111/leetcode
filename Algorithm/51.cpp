#include "../base.h"

/*
Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > t_vecRet;
        vector<string> t_vecIter;
        vector<pair<int,int> > t_vecLocate;
        if(n==0) return t_vecRet;
        int i,j =0 ;
        t_vecLocate.push_back(make_pair<int,int>(i,j));
        do{

        }while(true)
        return t_vecRet;
    }
    bool isCorrected( vector<pair<int,int> > &base)
    {
        vector<int> first;
        vector<int> send;
        for(vector<pair<int,int> >::iterator iter = base.begin();iter!=base.end();iter++)
        {
            first.push_back(iter->first);
            send.push_back(iter->second);
        }
        sort(first.begin(),first.end());
        sort(send.begin(),send.end());
       return (first.size()==distance(first.begin(),unique(first.begin(),first.end())))&&(send.size()==distance(send.begin(),unique(send.begin(),send.end())));
    }
    string BuildLine(int n,int k)
    {
        string t_strRet;
        for(int i = 0;i<n;i++)
        {
            if(i==k)
            {
                t_strRet +="Q";
            }
            else{
                t_strRet += ".";
            }
        }
    }

};
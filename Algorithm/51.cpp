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
    vector<vector<string> > solveNQueens1(int n) {
        vector<vector<string> > t_vecRet;
        vector<string> t_vecIter;
        vector<pair<int,int> > t_vecLocate;
        if(n==0) return t_vecRet;
        int i=0,j =0 ;
        t_vecLocate.push_back(make_pair(i,j));
        t_vecIter.push_back(BuildLine(n,j));
        if(n==1)
        {
            t_vecRet.push_back(t_vecIter);
            return t_vecRet;
        }
        i++;
        do{
            t_vecLocate.push_back(make_pair(i,j));
            t_vecIter.push_back(this->BuildLine(n,j));
            Display(t_vecIter);
            if(isCorrected(t_vecLocate)){
                if(t_vecIter.size()==n)
                {
                    t_vecRet.push_back(t_vecIter);
                    if(!Fun(i,j,t_vecLocate,t_vecIter,n))
                    {
                        return t_vecRet;
                    }
                    continue;
                }
                else{
                    i++;//i will not greater than n-1
                    j=0;
                    continue;
                }
            }
            else{
                t_vecLocate.pop_back();
                t_vecIter.pop_back();
                j++;
                if(j>n-1)
                {
                    if(!Fun(i,j,t_vecLocate,t_vecIter,n))
                    {
                        return t_vecRet;
                    }
                    continue;
                }
 

            }
        }while(true);
        return t_vecRet;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > t_vecRet;
        int i =0,j = 0;
        t_vecRet.clear();
        t_vecIter.clear();
        t_vecLocate.clear();
        backtrack(t_vecRet,i,j,n);
        return t_vecRet;
    }
private:
    vector<string> t_vecIter;
    vector<pair<int,int> >t_vecLocate;

private:
    void backtrack(vector< vector<string> >&t_vecRet,int i,int j,const int &n)
    {
       // Display(t_vecIter);
        if((!t_vecLocate.empty())&&(t_vecLocate.back().first>=n))
        {
            return;
        }
        if(!isCorrected(t_vecLocate))
        {
            return;
        }
        if(t_vecIter.size()==n&&isCorrected(t_vecLocate)){
            t_vecRet.push_back(t_vecIter);
            return ;
        }

        for(int k = 0;k<n;k++)
        {
            t_vecIter.push_back(BuildLine(n,k));
            t_vecLocate.push_back(make_pair(i,k));
            backtrack(t_vecRet,i+1,0,n);
            t_vecIter.pop_back();
            t_vecLocate.pop_back();

        }
    }
    bool isCorrected( vector<pair<int,int> > &base)
    {
        if(base.empty()){
            return true;
        }
        vector<int> first;
        vector<int> send;
        for(vector<pair<int,int> >::iterator iter = base.begin();iter!=base.end();iter++)
        {
            first.push_back(iter->first);
            send.push_back(iter->second);
        }
        sort(first.begin(),first.end());
        sort(send.begin(),send.end());

        bool b1 =  (first.size()==distance(first.begin(),unique(first.begin(),first.end())))&&(send.size()==distance(send.begin(),unique(send.begin(),send.end())));
        if(!b1){
            return false;
        }
        for(int i = 0;i<(base.size()-1);i++){
            for(int j = i+1;j<(base.size());j++)
            {
                double k = (double)((base[j].first)-(base[i].first))/((base[j].second)-(base[i].second));
                if(k == 1||k==-1) return false;
            }
        }
        return true;
    }
    string BuildLine(const int &n,const int &k)
    {
        string t_strRet="";
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
        return t_strRet;
    }
    bool Fun(int &i,int &j,vector<pair<int,int> >&t_vecLocate,vector<string> &t_vecIter,const int &n){
        int t_nLen = t_vecLocate.size();
        cout<<"t_nLen "<<t_nLen<<endl;;
        cout<<i<<" "<<j<<endl;
        if(t_nLen == 0)
        {
            return false;

        }
        pair<int,int> tmp = t_vecLocate.back();
        string tmp1 = t_vecIter.back();
        t_vecLocate.pop_back();
        t_vecIter.pop_back();

        int t_ni = tmp.first;
        int t_nj = tmp.second;
        i = t_ni;
        j = t_nj+1;
        if(j>n-1){
            return Fun(i,j,t_vecLocate,t_vecIter,n);
        }
        else{
            return true;
        }
        return false;
    } 



};
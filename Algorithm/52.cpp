#include "../base.h"
class Solution {
public:
    int totalNQueens(int n) {
        int t_nRet = 0;
        int i =0,j = 0;
        t_vecLocate.clear();
        backtrack(t_nRet,i,j,n);
        return t_nRet;
    }
private:
    
    vector<pair<int,int> >t_vecLocate;

private:
    void backtrack(int &t_nRet,int i,int j,const int &n)
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
        if(t_vecLocate.size()==n&&isCorrected(t_vecLocate)){
            t_nRet++;
            return ;
        }

        for(int k = 0;k<n;k++)
        {
            t_vecLocate.push_back(make_pair(i,k));
            backtrack(t_nRet,i+1,0,n);
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
};
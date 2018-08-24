#include "../base.h"

class Solution {
public:
    int uniquePaths_tmp(int m, int n) {//回溯法。 Time Limit Exceeded
        int t_nRet=0;
        pair<int,int> Locate;
        Locate.first = 0;
        Locate.second = 0;
        backtrack(t_nRet,Locate,m,n);
        return t_nRet;
    }

    int uniquePaths1(int m,int n)//   O(2^min(m,n))<O<O(2^max(m,n))  指数级的时间复杂度
    {
        if(1==m) return 1;
        if(1==n) return 1;
        return uniquePaths1(m-1,n)+uniquePaths1(m,n-1);
    }
    int uniquePaths2(int m,int n){//O(m*n) 空间复杂度  O(m*n)
        if(1==m) return 1;
        if(1==n) return 1;
        map<pair<int,int>,int>::iterator iter = t_mapNote.find(make_pair(m,n));
        if(iter!=t_mapNote.end()){
            return iter->second;
        }
        else{
            int value = uniquePaths2(m-1,n)+uniquePaths2(m,n-1);
            t_mapNote[make_pair(m,n)] = value;
            return value;
        }
    }

    int uniquePaths3(int m,int n){//自底向上，时间复杂度和空间复杂度理论上应该是和方法2相同，但运行时间快很多。也许是没有 map.find()的原因。 
        int count[m][n];
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
                count[i][j]=  count[i][j-1]+count[i-1][j];
            }
        }
        return count[m-1][n-1];

    }
private:
    map<pair<int,int>,int> t_mapNote;



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

 public:   
    int Fun(int n){//O(2^n)
        if(n==1){
            return 1;

        }
        if(n==2)
        {
            return 2;
        }
        return Fun(n-1)+Fun(n-2);
    }
    int Fun2(int n){//O(n)
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        map<int,int>::iterator iter = tmp.find(n);
        if(iter!=tmp.end()){
            return tmp[n];
        }
        else{
            int value = Fun2(n-1)+Fun2(n-2);
            tmp[n]=value;
            return value;
        }

    }
    int Fun3(int n)//空间复杂度降为1 。 虽然Fun3和Fun2的时间复杂度都是 O(N),但是Fun3的运行时间还是显著低于Fun2
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int a = 1;
        int b = 2;
        int tmp = 0;
        for(int i = 3;i<=n;i++){
            tmp = a+b;
            a = b;
            b = tmp;

        }
        return tmp;
    }
private:

    map<int,int> tmp;

};
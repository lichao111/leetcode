#include "../base.h"

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int t_nRet = 0;
        vector<vector<string> > t_vecRet;
        vector<string> t_vecIter;

        for(int i = 0;i<A.size();i++)
        {
            t_vecIter.push_back(A[i]);
            for(int j= i+1;j<A.size();)
            {
                 if(equ(A[i],A[j]))
                 {
                    t_vecIter.push_back(A[j]);
                    A.erase(A.begin()+j);
                 }
                 else{
                     j++;
                 }
            }
            t_vecRet.push_back(t_vecIter);
            t_vecIter.clear();
        }
        DisplayVecofVec(t_vecRet);
        return t_vecRet.size();
    }
private:
    bool equ(string &a1,string &a2)
    {
        if(a1.size()!=a2.size()) return false;
        string a11="";
        string a12="";
        string a21="";
        string a22="";
        for(int i = 0;i<a1.size();i++)
        {
            if(i%2==0){
                a12+=a1[i];
                a22+=a2[i];
            }
            else{
                a11+=a1[i];
                a21+=a2[i];
            }
        }
        sort(a12.begin(),a12.end());
        sort(a22.begin(),a22.end());
        sort(a11.begin(),a11.end());
        sort(a21.begin(),a21.end());

        cout<<a12<<endl;
        cout<<a22<<endl;
        if(a12.compare(a22)!=0) return false;
        if(a11.compare(a21)!=0) return false;
        return true;
    }
};

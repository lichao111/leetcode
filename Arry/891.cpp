#include "../base.h"
/*
Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        if(A.size()==0||A.size()==1)
        {
            return 0;
        }
        vector<vector<int> >sub = this->subset(A);
        //DisplayVecofVec(sub);
        //cout<<"--"<<endl;
        int t_nSum = 0;
        vector<int> t_nTmp;
        for(int i = 0;i<sub.size();i++){
            t_nTmp = sub[i];
            sort(t_nTmp.begin(),t_nTmp.end());
            //Display(t_nTmp);
            t_nSum += (*(t_nTmp.end()-1))-(*(t_nTmp.begin()));
           // cout<<t_nSum<<endl;
        }
        return t_nSum%(int)(pow(10,9)+7);
    }
    vector<vector<int> > subset_1(vector<int> &A){
        vector<vector<int> > t_nRet;
        vector<int> t_vecIter;
        if(A.size()==0){
            return t_nRet;
        }
        else if(A.size()==1){
            t_nRet.push_back(A);
            return t_nRet;
        }
        else{
            int k = A.back();
            t_vecIter.push_back(k);
            t_nRet.push_back(t_vecIter);
            t_vecIter.clear();
            A.pop_back();
            vector<vector<int> > bb = subset(A);
            for(int i = 0;i<bb.size();i++){
                t_nRet.push_back(bb[i]);
                bb[i].push_back(k);
                t_nRet.push_back(bb[i]);
            }
        }
        return t_nRet;
        
    }
    vector<vector<int> > subset(vector<int> &A){
        vector<vector<int> > t_vecRet;
        vector<int> t_vecIter;
        backtrack(t_vecRet,t_vecIter,0,A);
        return t_vecRet;
    }
    void backtrack(vector<vector<int > > &t_vecRet,vector<int> &t_vecIter,int index,vector<int> &A){
        if(index == A.size()) return ;
        //t_vecRet.push_back(t_vecIter);
        t_vecIter.push_back(A[index]);
        t_vecRet.push_back(t_vecIter);
        backtrack(t_vecRet,t_vecIter,index+1,A);
        t_vecIter.pop_back();       
        //t_vecRet.push_back(t_vecIter);
        backtrack(t_vecRet,t_vecIter,index+1,A);
    }
};
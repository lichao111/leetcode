#include "../base.h"

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string t_strRet = "";
        for(int i = 0 ;i<n;i++){
            t_vecBox.push_back(i+'1');
        }
        //Display(t_vecBox);
        int t_nTmp = 0;
        int t_nindex  = 0;
        while(n--){
            t_nTmp =  factorial(n);
            t_nindex = k/t_nTmp + (k%t_nTmp==0?0:1);
           // cout<<"t_nindex"<<t_nindex<<endl;
            t_strRet += t_vecBox[t_nindex-1];
            t_vecBox.erase(t_vecBox.begin()+(t_nindex-1));
            k -= ((t_nindex-1)*t_nTmp);
            //cout<<"k"<<k<<endl;
            //cout<<t_strRet<<endl;
        }
        return t_strRet;
        
    }
    int factorial(int n){
        int t_nRet  =1;
        while(n){
            t_nRet *= (n--);
        }
        return t_nRet;
    }

private:
    vector<char> t_vecBox;
};
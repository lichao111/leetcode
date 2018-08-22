#include "../base.h"

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
//一种方法是生成所有的排序，然后遍历删除。 复杂度是 O(2^2n-1)
//另一种方法是回溯法
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> t_vecRet;
        string t_strTmp="";
        int index = 0;
        backtrack(n,t_strTmp,t_vecRet);
        return t_vecRet;
    }

private:
    void backtrack(const int &n, string &t_strTmp,vector<string> &t_vecRet){
        if(!isCorrect(t_strTmp,n)){
            return ;
        }
        if(t_strTmp.size()==2*n)
        {
            t_vecRet.push_back(t_strTmp);
            return;
        }
        t_strTmp+="(";
        backtrack(n,t_strTmp,t_vecRet);
        t_strTmp[t_strTmp.size()-1]=')';
        backtrack(n,t_strTmp,t_vecRet);
        t_strTmp.erase(t_strTmp.size()-1,1);
        return ;
    }
    bool isCorrect(string tmp,const int &n)
    {
        int t_count=0;
        int t_N = 0;
        for(int i= 0;i<tmp.size();i++){
            if(tmp[i]=='('){
                t_count++;
                t_N++;
            }
            else{
                if(t_count==0)
                {
                    return false;
                }
                else{
                    t_count--;
                }
            }
            
        }
        if(t_N>n){
            return false;
        }
        return true;
    }
};
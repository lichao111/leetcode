#include "../base.h"
/*
Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
*/

class Solution
{
  public:
    int sumSubseqWidths(vector<int> &A)//先把最大数加起来，再减去所有最小数加起来。此题如果计算子集会超时
    {
       long  int t_nRet = 0;
       long c = 1;
       sort(A.begin(),A.end());
       for(int i = 0;i<A.size();i++,c=(c<<1)%1000000007){
           t_nRet = (t_nRet + A[i]*c-A[A.size()-i-1]*c)%1000000007;
           //t_nRet %= 1000000007;
       }
       return (t_nRet)%1000000007;
    }
    vector<vector<int> > subset_1(vector<int> &A)
    {
        vector<vector<int> > t_nRet;
        vector<int> t_vecIter;
        if (A.size() == 0)
        {
            return t_nRet;
        }
        else if (A.size() == 1)
        {
            t_nRet.push_back(A);
            return t_nRet;
        }
        else
        {
            int k = A.back();
            t_vecIter.push_back(k);
            t_nRet.push_back(t_vecIter);
            t_vecIter.clear();
            A.pop_back();
            vector<vector<int> > bb = subset_1(A);
            for (int i = 0; i < bb.size(); i++)
            {
                t_nRet.push_back(bb[i]);
                bb[i].push_back(k);
                t_nRet.push_back(bb[i]);
            }
        }
        return t_nRet;
    }
    vector<vector<int> > subset(vector<int> &A)
    {
        vector<vector<int> > t_vecRet;
        vector<int> t_vecIter;
        backtrack(t_vecRet, t_vecIter, 0, A);
        return t_vecRet;
    }
    void backtrack(vector<vector<int> > &t_vecRet, vector<int> &t_vecIter, int index, vector<int> &A)
    {
        if (index == A.size())
            return;
        //t_vecRet.push_back(t_vecIter);
        t_vecIter.push_back(A[index]);
        t_vecRet.push_back(t_vecIter);
        backtrack(t_vecRet, t_vecIter, index + 1, A);
        t_vecIter.pop_back();
        //t_vecRet.push_back(t_vecIter);
        backtrack(t_vecRet, t_vecIter, index + 1, A);
    }

    void print_subset(int n, int *A, int cur)
    {
        for (int i = 0; i < cur; i++)
        {
            printf("%d ", A[i]); // 打印当前集合
        }
        printf("\n");
        int s = cur ? A[cur - 1] + 1 : 0; // 确定当前元素的最小可能值
        for (int i = s; i < n; i++)
        {
            A[cur] = i;
            print_subset(n, A, cur + 1); // 递归构造子集
        }
    }

    vector<vector<int > > subset_bit(vector<int> p_vecSet){
        vector<vector<int> > t_vecRet;
        vector<int> t_vecIter;
        int i = (1<<(p_vecSet.size()));
        for(int k = 0;k<i;k++){
            for(int j = 0;j<p_vecSet.size();j++){
                if((1<<j)&k){
                    t_vecIter.push_back(p_vecSet[j]);
                }
            }
            t_vecRet.push_back(t_vecIter);
            t_vecIter.clear();
        }
        return t_vecRet;
    }
};

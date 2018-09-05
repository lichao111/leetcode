#include "../base.h"
/*
Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]

Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.  (less than int_max)
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
*/
class FreqStack
{
  public:
    FreqStack()
    {
        t_nMaxCount=0;
        t_mapStack.clear();
        t_mapCount.clear();
    }

    void push(int x)
    {
        t_mapCount[x]++;
        t_mapStack[t_mapCount[x]].push_back(x);
        if(t_mapCount[x]>t_nMaxCount){
            t_nMaxCount =  t_mapCount[x];
        }
    }

    int pop()
    {
       int t_nRet = t_mapStack[t_nMaxCount].back();
       t_mapStack[t_nMaxCount].pop_back();
        t_mapCount[t_nRet]--;
        if(t_mapStack[t_nMaxCount].empty())
        {
            t_nMaxCount--;
        }
       return t_nRet;
    }

  private:
    map<int, vector<int> > t_mapStack;
    map<int,int> t_mapCount;
    int t_nMaxCount;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
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
        stk.clear();
        t_mapCount.clear();
        t_nMaxLocation.clear();
        t_nMaxLocation.push_back(0);
    }

    void push(int x)
    {
        stk.push_back(x);
        t_mapCount[x]++;
        cout<<t_nMaxLocation.back()<<endl;
        if(t_mapCount[x]>=t_mapCount[t_nMaxLocation.back()]){
            t_nMaxLocation.push_back(stk.size());
        }
        else{
            t_nMaxLocation.push_back(t_nMaxLocation.back());
        }
       // Displaymap(t_mapCount);
    }

    int pop()
    {
        int t_nRet = *(stk.begin() +t_nMaxLocation.back());

        t_mapCount[t_nRet]--;
        cout<<t_nMaxLocation.back()<<endl;
        stk.erase(stk.begin() +t_nMaxLocation.back());
        t_nMaxLocation.pop_back();

        return t_nRet;
    }

  private:
    vector<int> stk;
    map<int, int> t_mapCount;
    vector<int> t_nMaxLocation;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
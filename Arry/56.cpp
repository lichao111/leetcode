#include "../base.h"
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a1, Interval a2)
{
    if (a1.start == a2.start)
        return a1.end < a2.end;
    return a1.start < a2.start;
}
class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        typedef bool (*PTRFUN)(Interval,Interval);
        PTRFUN pFun;
        pFun = compare;
        sort(intervals.begin(), intervals.end(), pFun);
        vector<Interval> t_vecRet;
        t_vecRet.clear();
        if (intervals.empty())
            return t_vecRet;
        t_vecRet.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if ((t_vecRet.back()).end >= intervals[i].start)
            {
                if((t_vecRet.back()).end<(intervals[i].end))
                {
                    Interval a((t_vecRet.back()).start, intervals[i].end);
                    t_vecRet.pop_back();
                    t_vecRet.push_back(a);
                }
                else{
                    continue;
                }
            }
            else
            {
                t_vecRet.push_back(intervals[i]);
            }
        }
        return t_vecRet;
    }
};
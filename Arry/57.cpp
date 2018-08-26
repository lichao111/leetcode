#include "../base.h"


 //Definition for an interval.
  struct Interval {
     int start;
      int end;
     Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  }
 
 
bool compare(Interval a1, Interval a2)
{
    if (a1.start == a2.start)
        return a1.end < a2.end;
    return a1.start < a2.start;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return this->merge(intervals);
    }

private:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
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
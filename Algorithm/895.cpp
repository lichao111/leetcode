#include "../base.h"
class FreqStack {
public:
    FreqStack() {
        stk.clear();
        t_mapCount.clear();
    }
    
    void push(int x) {
        stk.push_back(x);
        t_mapCount[x]++;
    }
    
    int pop() {
        int t_tmp = stk.size()-1;
        
            for(int j = stk.size()-2;j>=0;j--){
                if(t_mapCount[stk[t_tmp]]>=t_mapCount[j]){
                    continue;
                }
                else{
                    t_tmp = j;
                }
            }
         cout<<t_tmp<<endl;
        int t_nRet = *(stk.begin()+t_tmp);
        t_mapCount[t_nRet]--;
        stk.erase(stk.begin()+t_tmp);
        return    t_nRet;
    }

private:
        vector<int> stk;
        map<int,int > t_mapCount;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
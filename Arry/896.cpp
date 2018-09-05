#include "../base.h"


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size()<=2) return true;
        bool ok ;
        bool tmp ;
        bool k = true;
        for(int i = 0;i<A.size()-1;i++){
                int j = i+1;
                if(A[i]==A[j]) continue;
                else if(k){
                    k = false;
                    ok =  (A[i]>=A[j]);
                }
                else{
                    tmp=(A[i]>=A[j]);
                    if(tmp!=ok) return false;
                }
            }
        
        return true;
    }
};
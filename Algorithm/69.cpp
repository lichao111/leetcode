#include "../base.h"

class Solution {
public:
    int mySqrt(int x) {
        long long int ret;
        for(int i = 0;i<=x;i++)
        {
           // if(i == 46340) {cout<<i*i<<endl;cout<<(i+1)*(i+1)<<endl;}
            if((i*i)==x){
                return i;
            }   
            ret = ((long long int)(i+1))*(i+1);
            if(ret>x){
                return i;
            }
        }
        return 0;
    }
};
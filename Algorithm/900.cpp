#include "../base.h"

/*Input: ["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
Output: [null,8,8,5,-1]
Explanation: 
RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
This maps to the sequence [8,8,8,5,5].
RLEIterator.next is then called 4 times:

.next(2) exhausts 2 terms of the sequence, returning 8.  The remaining sequence is now [8, 5, 5].

.next(1) exhausts 1 term of the sequence, returning 8.  The remaining sequence is now [5, 5].

.next(1) exhausts 1 term of the sequence, returning 5.  The remaining sequence is now [5].

.next(2) exhausts 2 terms, returning -1.  This is because the first term exhausted was 5,
but the second term did not exist.  Since the last term exhausted does not exist, we return -1.*/
class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        for(int i = 0;i<A.size();i+=2){
          
            if(A[i]!=0){
                pair<int,int> tmp(A[i+1],A[i]);
                box.insert(tmp);
                loca.push_back(A[i+1]);
            }
        }
        Displaymap(this->box);
        Display(loca);
        return;
    }
    
    int next(int n) {
        int k = 0;
        
        for(int i=0;i<loca.size();i++){
            if(box[loca[i]]>=n){
                k = loca[i];
                box[loca[i]] -= n;
                Displaymap(box);
                return k;
            }
            else{
                n-= box[loca[i]];
                box[loca[i]]=0;
            }
        }
        return -1;

    }
private:
     map<int,int> box;
     vector<int> loca;
    
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
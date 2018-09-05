#include "../base.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        if(p&&q){
            if((p->val)!=(q->val))
                return false;
        }
        if((p&&!q)||(!p&&q)) return false;
        if(!isSameTree(p->left,q->left))
        {
            return false;
        }

        if(!isSameTree(p->right,q->right))
        {
            return false;
        }
        return true;

    }
};
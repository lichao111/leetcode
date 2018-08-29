#include "../base.h"
/*A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.*/

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> t_vecRet;
        if(N%2==0) return t_vecRet;
        TreeNode *root = new TreeNode(0);
        if(N==1) { t_vecRet.push_back(root); return t_vecRet;}
        for(int i = 1;i<N;i+=2){
            if((N-i-1)<1) continue;
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-i-1);
            for(vector<TreeNode*>::iterator iter = left.begin();iter!=left.end();iter++){
                for(vector<TreeNode*>::iterator iter1 = right.begin();iter1!=right.end();iter1++){
                    TreeNode *root1 = new TreeNode(0);
                    root1->left = *iter;
                    root1->right = *iter1;
                    t_vecRet.push_back(root1);
                }
            }
        }
        return t_vecRet;
    }
};
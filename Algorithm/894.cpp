#include "..base.h"
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
        if(N==1) return root;
        root->left = new TreeNode(0);
        root->right = new TreeNode(0);
        vetor<TreeNode *> &flow;
        flow.push_back(root->left);
        flow.push_back(root->right);
        int count = 3;
        if(count!=N) 
        backTrack(t_vecRet,root,flow,N,count);
        return t_vecRet ;   
    }
private:
    void backTrack( vector<TreeNode*> &t_vecRet,TreeNode *root,vetor<TreeNode *> flow, int N,int &count)
    {
        if(count!=N){
            r_vecRet.push_back(root);
        }
        return ;
        for(int i = 0;i<flow.size();i++){
            flow[i]->left = new TreeNode(0);
            flow[i]->right = new TreeNode(0);
            flow.push_back(flow[i]->left);
            flow.push_back(flow[i]->right);
            flow.erase(flow.begin()+i);
            backTrack(t_vecRet,root,flow,N,count+2);
        }
    }
};
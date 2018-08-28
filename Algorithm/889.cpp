#include "../base.h"
/*
Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
*/


//以下组合是否可以唯一确定一个二叉树
//前 + 中 可以
//后 + 中 可以
//前 + 后 不可以

//此题就是第三种情况

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size()==0) return NULL;
        TreeNode *root = new TreeNode(*(pre.begin()));
        if(pre.size()==1){
            return root;
        }
        else if(pre.size()==2){
            (root->left) = new TreeNode(pre[1]);
            return root;
        }
        else if(pre.size()==3){
            if(pre[1]==post[0])
            {
                (root->left) = new TreeNode(pre[1]);
                (root->right) = new TreeNode(pre[2]);
            }
            else{
                (root->left) = new TreeNode(pre[1]);
                 (root->left)->left = new TreeNode(pre[2]);
            }
            return root;
        }
        vector<int> t_vecpre;
        vector<int> t_vecpost;
        FindVector(pre,post,pre[1],t_vecpre,t_vecpost);  
        root->left = constructFromPrePost(t_vecpre,t_vecpost);
        cout<<"------------"<<endl;
        Display(pre);
        Display(post);
        t_vecpre.clear();
        t_vecpost.clear();
        if(pre.size()<=1) {
            root->right = NULL;
        }
        else{
            FindVector(pre,post,pre[1],t_vecpre,t_vecpost); 
            root->right = constructFromPrePost(t_vecpre,t_vecpost);
        }
        return root;
    }

private:    
    void FindVector( vector<int> &pre, vector<int>&post,int p_nObject,vector<int> &outpre,vector<int> &outpost){
        
        int i = 0;
        for(;i<post.size();i++){
            outpost.push_back(post[i]);
            if(post[i]==p_nObject)
            break;
        }
        post.erase(post.begin(),post.begin()+i+1);
        int j = 1;
        for(;j<=i+1;j++){
            outpre.push_back(pre[j]);
        }
        pre.erase(pre.begin()+1,pre.begin()+1+i+1);
        return;
    }
};
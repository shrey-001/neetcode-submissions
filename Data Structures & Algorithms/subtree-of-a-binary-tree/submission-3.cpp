/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // bool found = false ; 

    // bool dfs(TreeNode* root, TreeNode* subRoot){
    //     if(!root && !subRoot)return true;
    //     if(root && !subRoot)return true;
    //     if(!root && subRoot)return false;
    //     if(root->val == subRoot->val){
    //         bool f = true ; 
    //         // if(subRoot)
    //         f &= (dfs(root->left , subRoot->left) && dfs(root->right , subRoot->right)) ;
    //         return f ;
    //     }
    //     return dfs(root->left , subRoot) || dfs(root->right , subRoot) ; 
    // }
    map<TreeNode* , string> hash ; 
    string traverse(TreeNode* root , bool flag) { 
        if(!root)return "+" ; 
        string str  ; 
        str =  to_string(root->val) + "+" + traverse(root->left, flag) + "+" + traverse(root->right, flag) ;
        if(flag)hash[root] = str ; 
        return str ; 
    }
    // void traverse(TreeNode* root) { 
    //      if(!root)return; 
    //      string hs = get(root) ; 
    //      hash[root] = hs ; 
    // }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string current = traverse(subRoot , false) ; 
        // traverse()
        string np = traverse(root , true) ; 
        for(auto &ip : hash){
            if(ip.second == current)return true ;
        }
        return false ; 
    }
};

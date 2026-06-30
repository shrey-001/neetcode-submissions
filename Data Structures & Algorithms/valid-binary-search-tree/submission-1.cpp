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
    void dfs(TreeNode* root, vector<int>& preorder){
        if(!root) return ;
        if(root->left) {
            dfs(root->left, preorder);
        }
        preorder.push_back(root->val);
        if(root->right) {
            dfs(root->right, preorder);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> preorder;

        dfs(root, preorder);

        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<=preorder[i-1]) return false;
        }
        return true;
    }
};

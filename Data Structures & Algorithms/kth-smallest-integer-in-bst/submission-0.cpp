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
    void dfs(TreeNode* root, vector<int>& inorder, int k){
        if(!root) return;
        if(inorder.size()==k) return;
        if(root->left) dfs(root->left, inorder, k);
        inorder.push_back(root->val);
        if(root->right) dfs(root->right, inorder, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;

        dfs(root, inorder, k);
        return inorder[k-1];
    }
};

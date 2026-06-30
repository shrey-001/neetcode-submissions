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
    
    int dfs(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int leftHeight=dfs(root->left, ans);
        int rightHeight=dfs(root->right,ans);

        int curr = leftHeight +rightHeight;
        ans = max(ans, curr);
        return 1+max(leftHeight, rightHeight);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0 ;
        dfs(root, ans);
        return ans;
    }
};

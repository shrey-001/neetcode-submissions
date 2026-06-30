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
    int count;
    void dfs(TreeNode* root, int currMax){
        if(!root) return ;
        if(root->val>=currMax) count++;
        if(root->left){
            dfs(root->left, max(currMax, root->left->val));
        }
        if(root->right){
            dfs(root->right, max(currMax, root->right->val));
        }
    }
    int goodNodes(TreeNode* root) {
        count=0;
        dfs(root, root->val);
        return count;
        
    }
};

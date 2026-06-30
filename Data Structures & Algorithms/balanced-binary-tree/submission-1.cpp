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
    unordered_map<TreeNode*, int> mp;

    int height(TreeNode* root){
        if(!root) return 0;

        if(mp.find(root)!=mp.end()) return mp[root];

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return mp[root] = 1+ max(leftHeight, rightHeight);

    }
    bool dfs(TreeNode* root){
        if(!root) return true;
        int leftHeight= 0, rightHeight=0;
        if(root->left) leftHeight = mp[root->left];
        if(root->right) rightHeight = mp[root->right];

        if(abs(leftHeight-rightHeight)>1) return false;
        return dfs(root->left) && dfs(root->right);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return dfs(root);
    }
};

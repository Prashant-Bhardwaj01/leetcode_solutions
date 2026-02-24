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
    int dfs(TreeNode* root, int cur){
        if(!root) return 0;
        cur = cur*2 + root->val;
        if(!root->left && !root->right) return cur;
    
        int l = dfs(root->left,cur);
        int r = dfs(root->right, cur);
        return l+r;
    }
    int sumRootToLeaf(TreeNode* root) {
        int cur = 0;
        return dfs(root,cur);
    }
};

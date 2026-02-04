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
    int dfs(TreeNode* root,int& d){
        if(!root) return 0;
        int l = dfs(root->left,d);
        int r = dfs(root->right,d);
        d = max(l+r,d);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dfs(root,d);
        return d;

    }
};

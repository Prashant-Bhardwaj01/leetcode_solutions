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
    int dfs(TreeNode* root, int& dist){
        if(!root) return 0;
        int l = dfs(root->left,dist);
        int r = dfs(root->right,dist);
        dist = max(l+r,dist);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dist =0;
        dfs(root,dist);
        return dist;
    }
};

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
    int  dfs(TreeNode* root, int& sum){
        if(!root) return 0;
        int l = dfs(root->left,sum);
        int r = dfs(root->right,sum);
        if(l<0) l=0;
        if(r<0) r=0;
        sum = max(l+r+root->val,sum);
        return max(l,r)+root->val; 
    }
    int maxPathSum(TreeNode* root) {
        int sum =root->val;
        // if((root->val < 0) && !root->left && !root->right) return root->val ;

        dfs(root,sum);
        return sum;
    }
};

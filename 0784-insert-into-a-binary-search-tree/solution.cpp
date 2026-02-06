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
    TreeNode* dfs(TreeNode* root,int val){
        if(!root) {
            return root;
        }
        if(val < root->val){
            if(root->left != nullptr){
                dfs(root->left,val);
            }else{
                root->left = new TreeNode(val);
            }
            
        }else{
            if(root->right != nullptr){
                dfs(root->right,val);
            }else{
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        return dfs(root,val);
    }
};

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
    bool ans(TreeNode* root,int sum,int targetSum){
        if(!root){
           return 0; 
        }
        sum += root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                return true;;
            return false;
        }
        }
        
        return ans(root->left,sum,targetSum)|| ans(root->right,sum,targetSum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        
        return ans(root,0,targetSum);
    }
};

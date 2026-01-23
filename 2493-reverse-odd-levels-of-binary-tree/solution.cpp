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
    void opp(TreeNode* l,TreeNode* r,int c){
        if(!l || !r) return ;
        if(c%2!=0){
            swap(l->val,r->val);
        }
            opp(l->left,r->right,c+1);
            opp(l->right,r->left,c+1);
        
        
        
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int c=0;
        opp(root->left,root->right,1);
        return root;
    }
};

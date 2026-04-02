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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int t, vector<int> sub,int sum){
        if(!root) return;
        sub.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right){
            if(sum == t)
            ans.push_back(sub);
            return ;
        }
        dfs(root->left, t, sub, sum);

        dfs(root->right,t,sub,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> sub;
        dfs(root,targetSum,sub,0);
        return ans;
    }
};

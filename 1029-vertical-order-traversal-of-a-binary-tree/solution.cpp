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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front = q.front();
            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;
            q.pop();
            mp[x][y].push_back(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        for(auto i:mp){
            vector<int> sub;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                sub.insert(sub.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(sub);
        }
        return ans;
    }
};

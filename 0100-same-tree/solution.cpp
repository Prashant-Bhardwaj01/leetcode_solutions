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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*>pq;
        queue<TreeNode*>qq;
        pq.push(p);
        qq.push(q);
        int l=0;
        while(!pq.empty() || !qq.empty()){
            int pl = pq.size();
            int ql = qq.size();
            for(int i=0;i<pl;i++){
                TreeNode* node1 = pq.front();
                pq.pop();
                TreeNode* node2 = qq.front();
                qq.pop();
                if(node1->val != node2->val) return false;
                
                if((node1->left && !node2->left)||(!node1->left && node2->left) || (!node1->right && node2->right)||(node1->right && !node2->right))return false;
                
                if(node1->left) pq.push(node1->left);
                if(node1->right) pq.push(node1->right);
                if(node2->left) qq.push(node2->left);
                if(node2->right) qq.push(node2->right);
            }
            l++;
        }
        return true;
    }
};

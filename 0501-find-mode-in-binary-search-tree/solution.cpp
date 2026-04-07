class Solution {
public:
    vector<int> ans;
    TreeNode* prev = nullptr;
    int count = 0;
    int maxCount = 0;

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val == root->val)
            count++;
        else
            count = 1;

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } 
        else if (count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }
};

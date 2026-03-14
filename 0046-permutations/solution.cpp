class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> sub, vector<bool>& vis){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }
        for(int x=0; x<nums.size();x++){
            if(vis[x]) continue;
            vis[x] = true;
            sub.push_back(nums[x]);
        
            dfs(x+1, nums, ans, sub, vis);
            sub.pop_back();
            vis[x] = false;
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        vector<bool> vis(nums.size(), false);
        dfs(0, nums, ans, sub, vis);
        return ans;
    }
};

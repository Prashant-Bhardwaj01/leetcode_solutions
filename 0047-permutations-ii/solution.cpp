class Solution {
public:
    int n ;
    void dfs(int idx, vector<int>& nums, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=idx; i<n; i++){
            if(st.find(nums[i]) != st.end())continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            dfs(idx+1, nums, ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        
        dfs(0,nums,ans);
        return ans;
    }
};

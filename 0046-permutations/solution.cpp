class Solution {
public:
    void dfs(int i,int n,vector<int>& nums, vector<vector<int>>& ans){
        if(i>=n){
            ans.push_back(nums);
            return ;
        }
        for(int s=i;s<n;s++){
            swap(nums[s],nums[i]);
            dfs(i+1,n,nums,ans);
            swap(nums[i],nums[s]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        dfs(0,n,nums,ans);
        return ans;
    }
};

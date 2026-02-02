class Solution {
public:
    int can(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + can(i+2,nums,dp);
        int skip = can(i+1,nums,dp);
        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return can(0,nums,dp);
    }
};

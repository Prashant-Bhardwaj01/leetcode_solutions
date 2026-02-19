class Solution {
public:
    int dfs(vector<int> & nums,int s,int idx,int flag,vector<int>& dp){
        if(idx<s) return 0;
        if(dp[idx] != -1) return dp[idx];
        int l = nums[idx] + dfs(nums,s,idx-2,flag,dp);
        int r = 0 + dfs(nums,s,idx-1,flag,dp);
        return dp[idx] = max(l,r);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        return max(dfs(nums,1,n-1,-1,dp), dfs(nums,0,n-2,1,dp2));
    }
};

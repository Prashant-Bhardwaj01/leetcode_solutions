class Solution {
public:
    int dfs(vector<int>& nums,int i, vector<int>& dp){
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        int l = nums[i] + dfs(nums,i-2,dp);
        int r = 0 + dfs(nums,i-1,dp);
        return dp[i] = max(l,r);
    }
    int dfs_tab(vector<int>& nums,vector<int>&  dp,int n){
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i] = nums[0];
                continue;
            }
            int l = nums[i] ;
            int r = 0;
            if(i-2>=0)
            l += dp[i-2];
            if(i-1>=0)
            r = 0 + dp[i-1];
            dp[i] = max(l,r);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        // return dfs(nums,n-1,dp);
        return dfs_tab(nums,dp,n);
    }
};

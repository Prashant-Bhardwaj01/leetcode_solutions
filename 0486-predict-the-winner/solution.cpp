class Solution {
public:
    int ans(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int l = nums[i] + min(ans(i+2, j,nums,dp),ans(i+1,j-1,nums,dp));
        int r = nums[j] + min(ans(i, j-2, nums,dp),ans(i+1,j-1,nums,dp));
        return dp[i][j]=max(l,r);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int p1 = ans(0,n-1,nums, dp);
        int p2 = sum-p1;
        return p1>=p2;
        
    }
};

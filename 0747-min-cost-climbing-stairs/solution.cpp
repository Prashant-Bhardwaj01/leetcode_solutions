class Solution {
public:
    
    int dfs(vector<int> & cost, int i, vector<int>& dp){
        if(i==0) return dp[i] = cost[0];
        if(i==1) return dp[i] = cost[1];
        if(dp[i] != -1) return dp[i];
        int l = dfs(cost,i-1,dp);
        int r = dfs(cost, i-2,dp);
        return dp[i] =  cost[i]+min(l,r);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(dfs(cost,n-1,dp),dfs(cost,n-2,dp));
    }
};

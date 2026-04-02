class Solution {
public:
    int m;
    int n;
    int dp[501][501][3];
    int dfs(int i, int j, int neu, vector<vector<int>>& coins){
        if(i>=m || j>=n) return INT_MIN/2;
        if(i==m-1 && j == n-1){
            if(coins[i][j] < 0 && neu > 0){
                return 0;
            }
            return coins[i][j];
        }
        if(dp[i][j][neu] != INT_MIN) return dp[i][j][neu];
        int take = coins[i][j] + max(dfs(i+1,j,neu,coins),dfs(i,j+1,neu,coins));
        int skip = INT_MIN/2;
        if(coins[i][j] < 0){
            if(neu>0){
                skip = max(dfs(i+1,j,neu-1,coins), dfs(i,j+1,neu-1,coins));
            }
        }
        return dp[i][j][neu] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        int ans = dfs(0,0,2,coins);
        return ans;
    }
};

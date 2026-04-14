class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>>& grid, int i,int j){
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size() - 1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int l = dfs(grid,i,j+1);
        int r = dfs(grid,i+1,j);
        return dp[i][j]=grid[i][j]+min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0);
       
    }
};

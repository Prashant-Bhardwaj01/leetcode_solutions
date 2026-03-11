class Solution {
public:
    int dfs(int i,int j, int m, int n, vector<vector<char>>& mat, int& ans,vector<vector<int>>& dp){
        if(i>=m || j>= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(mat[i][j] == '1'){
            dp[i][j] = min(dfs(i,j+1,m,n,mat,ans,dp),min(dfs(i+1,j+1,m,n,mat,ans,dp), dfs(i+1,j,m,n,mat,ans,dp))) + 1;
            ans = max(dp[i][j],ans);
            return  dp[i][j];
        }
        return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,m,n,matrix,ans,dp);
            }
        }
        return ans*ans;
    }
};

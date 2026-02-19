class Solution {
public:
    int dfs(int sr,int sc, int m, int n){
        if(sr==m-1 && sc == n-1 ) return 1;
        if(sr>=m || sc>= n) return 0;
        int l = 0;
        l += dfs(sr+1,sc,m,n);
        
        int r = 0;
        r += dfs(sr,sc+1,m,n);
        
        return l+r;
    }
    int memo(int sr,int sc, int m,int n,vector<vector<int>>& dp){
        if(sr == m && sc == n) return 1;
        if(sr > m || sc > n) return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        int l=0;
        int r = 0;
        if(sr+1 <=m ) l += memo(sr+1,sc,m,n,dp);
        if(sc+1 <= n) r += memo(sr,sc+1,m,n,dp);
        return dp[sr][sc] = l+r;
    }
    int uniquePaths(int m, int n) {
        // return dfs(0,0,m,n);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return memo(0,0,m-1,n-1,dp);
    }
};

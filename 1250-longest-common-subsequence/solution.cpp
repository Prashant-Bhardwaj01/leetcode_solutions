class Solution {
public:
    int dp[1001][1001];
    int dfs(int i, int j, int n, int m, string& text1, string& text2){
        if(i>n || j>m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])return dp[i][j] =  1+dfs(i+1,j+1,n,m,text1,text2);
        int l = dfs(i+1,j,n,m,text1,text2);
        int r = dfs(i,j+1,n,m,text1,text2);
        return dp[i][j] = max(l,r);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,n-1,m-1,text1,text2);
    }
};

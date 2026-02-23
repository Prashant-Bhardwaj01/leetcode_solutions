class Solution {
public:
    bool dfs(string s, string t,int i,int j,vector<vector<int>>& dp){
        if(i== s.size()) return true;
        if(j == t.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]) dp[i][j] = dfs(s,t,i+1,j+1,dp);
        else dp[i][j] = dfs(s,t,i,j+1,dp);
        return dp[i][j];
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return dfs(s,t,0,0,dp);
    }
};

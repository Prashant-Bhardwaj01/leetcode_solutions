class Solution {
public:
    int dp[302][27][27];
    int dist(int curr, int f){
        int x1 = curr/6;
        int y1 = curr%6;
        int x2 = f/6;
        int y2 = f%6;
        return abs(x2-x1)+abs(y1-y2);
    }
    int dfs(string& word, int i, int f1, int f2){
        if(i>=word.length()) return 0;
        int curr = word[i] - 'A';
        if(dp[i][f1][f2] != -1) return dp[i][f1][f2];
        if(f1==26 && f2==26){
            return dp[i][f1][f2] = dfs(word,i+1,curr,f2);
        }
        if(f2==26){
            int f22 = dfs(word,i+1,f1,curr);
            int f11 = dist(curr,f1)+dfs(word,i+1,curr,f2);
            return dp[i][f1][f2] = min(f11,f22);
        }
            int f11 = dist(curr,f1)+dfs(word,i+1,curr,f2);
            int f22 = dist(curr,f2)+dfs(word,i+1,f1,curr);
            return dp[i][f1][f2] = min(f11,f22);
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return dfs(word,0,26,26);
    }
};

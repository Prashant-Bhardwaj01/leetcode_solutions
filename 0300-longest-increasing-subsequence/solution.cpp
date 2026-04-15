class Solution {
public:
    int dp[2502][2502];
    int dfs(int i,int pi, vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int t = 0;
        if(pi == -1 || nums[i] > nums[pi]){
            t = 1+dfs(i+1,i,nums);
        }
        int nt = dfs(i+1,pi,nums);
        return dp[i][pi+1] = max(nt,t);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,-1,nums);
    }
};

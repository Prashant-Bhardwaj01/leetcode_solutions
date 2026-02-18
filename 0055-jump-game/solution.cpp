class Solution {
public:
    bool dfs(vector<int>& nums,int idx,vector<int>& dp){
        if(idx == nums.size()-1) return true;
        if(dp[idx] !=-1) return dp[idx];
        for(int jump = 1;jump<=nums[idx];jump++){
            if(dfs(nums,idx+jump,dp)) return dp[idx+jump] = 1;
        }
        return dp[idx] =0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);

        return dfs(nums,0,dp);
    }
};


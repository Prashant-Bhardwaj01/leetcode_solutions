class Solution {
public:
    int dfs(int idx,int n, vector<int> &nums, int sum, int& ans){
        if(idx == n) return 0;
        sum += nums[idx];
        ans = max(ans,sum);
        if(sum < 0) sum =0;
        dfs(idx+1,n,nums,sum,ans);
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        return dfs(0,nums.size(),nums,0,ans);
        
    }
};

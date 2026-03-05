class Solution {
public:
    int dfs(int target, int i, vector<int>& nums, int n,int sum){
        if(i==n){
            if(sum == target) return 1;
            else return 0;
        }
        int l = dfs(target, i+1, nums, n , sum-nums[i]);
        int r = dfs(target, i+1, nums, n , sum+nums[i]);
        return l+r;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dfs(target,0,nums,n,0);

    }
};

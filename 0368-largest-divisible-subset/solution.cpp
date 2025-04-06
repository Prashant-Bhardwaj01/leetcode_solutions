class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int max = 1;
        vector<int>dp(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    if(max < dp[i])
                    max = dp[i];
                }
            }
        }
        int last = -1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==max && (last%nums[i]==0 || last==-1)){
                ans.push_back(nums[i]);
                max-=1;
                last = nums[i];
            }
        }
        return ans;
    }
};

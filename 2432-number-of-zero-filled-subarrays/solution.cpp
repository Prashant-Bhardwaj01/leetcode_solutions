class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)c++;
            else c=0;
            ans += c;
        }
        return ans;
        
    }
};

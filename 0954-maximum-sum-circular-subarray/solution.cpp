class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, minimum = 0, maximum = 0;
        int maxSum = nums[0], minSum = nums[0];
        for(int i=0; i<nums.size(); i++){
            maximum = max(maximum + nums[i], nums[i]);
            maxSum = max(maxSum, maximum);

            minimum = min(minimum + nums[i], nums[i]);
            minSum = min(minimum,minSum);

            total += nums[i];
        }
        int normalSum = maxSum;
        int ans = total - minSum;
        if(minSum == total) return normalSum;
        return max(ans, normalSum);
        
    }
};

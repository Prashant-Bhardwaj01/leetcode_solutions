class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ele = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ele = max(nums[i], ele + nums[i]);
            ans = max(ele,ans);
        }
        return ans;
    }
};

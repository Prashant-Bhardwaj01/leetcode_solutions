class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i], nums[i]*minimum, nums[i]*maximum});
            minimum = min({nums[i], nums[i]*minimum, nums[i]*maximum});
            maximum = temp;
            ans = max(ans,maximum);
        }
        return ans;
    }
};

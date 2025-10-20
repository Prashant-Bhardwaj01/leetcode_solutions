class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums[i] = pow(nums[i],2);
        int l = 0,r = n-1;
        vector<int> ans(n);
        int pos = n-1;
        while(l<=r){
            if(nums[l]>nums[r]) ans[pos--] = nums[l++];
            else ans[pos--] = nums[r--];
        }
        return ans;
        
    }
};

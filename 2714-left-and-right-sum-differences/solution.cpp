class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n);
        ls[0] = 0;
        vector<int> rs(n);
        rs[n-1] = 0;
        vector<int> ans(n);
        for(int i=1;i<n;i++) ls[i] = nums[i-1]+ls[i-1];
        int rsum = 0;
        for(int i=n-2;i>=0;i--){
            rsum += nums[i+1];
            rs[i] = rsum ;
        }
        for(int i=0;i<n;i++) ans[i] = abs(ls[i] - rs[i]);
        return ans;
        
    }
};

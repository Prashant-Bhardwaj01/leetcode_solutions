class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int l = 0;
        int r = 0;
        int c = 0;
        while(r<n){
            if(nums[r] == 1){
                c++;
                r++;
                ans = max(c,ans);
            }
            else{
                r++;
                l=r;
                c=0;
            }
        }
        return ans;
    }
};

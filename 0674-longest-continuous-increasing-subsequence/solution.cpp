class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int ans = 0;
        int m = 1;
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>nums[i-1]){
                m++;
            }else{
                
                m=1;
            }
            ans = max(ans,m);
        }
        return ans;
    }
};

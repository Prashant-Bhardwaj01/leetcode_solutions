class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum=1;
        int ans=0;
        for(int i=0;i<n-1;i++){
            
            if(nums[i] == nums[i+1]){ 
                sum++;
            }
            else sum=1;
            if(sum==n/2){
                return nums[i];
            }
        }
        return ans;
    }
};

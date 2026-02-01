class Solution {
public:
    int can(vector<int>& nums, int mid,int n){
        int c=1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum+nums[i] <= mid){
                sum+=nums[i];
            }else{
                c++;
                sum = nums[i];
            }
        }
        return c;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return -1;
        int mx = INT_MIN;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx = max(mx,nums[i]);
        }
        if(n==k) return mx;
        int low = mx;
        int high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low+(high - low) /2;
            if(can(nums,mid,n) <= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};

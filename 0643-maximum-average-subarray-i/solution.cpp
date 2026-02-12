class Solution {
public:
    double max(double a, double b){
        return a>b?a:b;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum =0;
        for(int i=0;i<k;i++) sum += nums[i];
        double ans=sum;
        int l = 0;
        int r = k;
        
        while(r<n){
            sum+=nums[r];
            sum-=nums[l];
            r++;
            l++;
            ans = max(ans,sum);
        }
        return ans/k;
    }
};

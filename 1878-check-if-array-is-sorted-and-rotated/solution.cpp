class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]) r++;
            else break;
        }
        if(r==n-1) return true;
        
        int arr[n];
        int c=0;
        for(int i=r+1;i<n;i++){
            arr[c++] = nums[i];
        }
        for(int i =0;i<=r;i++){
            arr[c++] = nums[i];
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) return false;
        }
        return true;
    }
};

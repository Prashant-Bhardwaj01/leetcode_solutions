class Solution {
public:
    int binary(int l , int h ,vector<int>& nums, int t){
        if(l>h)return -1;
        
            int mid = l+(h-l) / 2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] < t) return binary(mid + 1,h,nums,t);
            else return binary(l,mid-1,nums,t);
        
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        return binary(l,h,nums,target);

    }
};

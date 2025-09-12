class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        while(low <= high){
            int mid = (low+high) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};

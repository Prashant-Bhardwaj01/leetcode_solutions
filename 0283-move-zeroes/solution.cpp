class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0)continue;
            else{
                nums[idx++] = nums[i];
            }
        }
        while(idx<n)nums[idx++] = 0;
    }
};

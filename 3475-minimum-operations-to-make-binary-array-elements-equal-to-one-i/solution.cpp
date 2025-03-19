class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int c=0;
        for(int i=0;i<size-2;i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                c++;
                }
        }
        if(nums[size - 2]==0 || nums[size - 1] == 0){
            return -1;
        }
        return c;
        }
 };


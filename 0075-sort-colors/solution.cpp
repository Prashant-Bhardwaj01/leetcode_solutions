class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int l = 0;
        // int r = nums.size()-1;
        // while(l<r){
        //     if(nums[l]<nums[r]){
        //         l++;
        //     }
        //     else if(nums[l]>nums[r]){
        //         swap(nums[l],nums[r]);
        //         r--;
        //     }else{
        //         l++;
        //         r--;
        //     }
        // }
        int n = nums.size();
        
        int z = 0;
        int f = 0;
        for(int i=0;i<n;i++){
            if( nums[i] == 0) z++;
            else if( nums[i] == 1)f++;
        }
        for(int i =0;i<n;i++){
            if(i<z) nums[i] = 0;
            else if(i<f+z) nums[i] = 1;
            else nums[i] = 2;
        }
        
    }
};

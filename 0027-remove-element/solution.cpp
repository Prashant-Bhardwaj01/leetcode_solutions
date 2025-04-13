class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                ans.push_back(nums[i]);
            
                c++;
            }
        }
        nums = ans;
        return c;
    }
}; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> ans;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     ans.insert(nums[i]);
        // }
        // for(int i=0;i<n;i++){
        //     nums.erase(nums.begin()+i);
        // }
        // nums.assign(ans.begin(),ans.end());
        // return nums.size();
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

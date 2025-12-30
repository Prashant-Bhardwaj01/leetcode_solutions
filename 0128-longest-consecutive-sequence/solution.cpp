class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i] + 1 == nums[i+1]){
                c++;
                ans = max(ans,c);
            }
            else if(nums[i] == nums[i+1]) continue;
            else c=0;

        }
        return ans+1;
    }
};

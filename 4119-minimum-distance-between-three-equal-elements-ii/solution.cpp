class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> freq;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            freq[nums[i]].push_back(i);
            if(freq[nums[i]].size() >= 3){
                int l_ind = freq[nums[i]].size()-1;
                int f_ind = l_ind - 3 +1;
                ans = min(ans,2*(freq[nums[i]][l_ind] - freq[nums[i]][f_ind]));
            }
        }
        return ans == INT_MAX? -1:ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int i : nums){
            freq[i]++;
        }
        for(auto i:freq){
            if(i.second > 1)
            ans.push_back(i.first);
        }
        return ans;
    }
};

class Solution {
public:
    void per(vector<int>& nums,int idx, vector<vector<int>>& ans, unordered_set<string>& vis){
        if(idx==nums.size()){
            string s;
            for(int i: nums) s+=to_string(i)+',';
            if(!vis.count(s)){
                vis.insert(s);
                ans.push_back(nums);
            }
            return ;
        } 
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            per(nums,idx+1,ans,vis);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<string> vis;
        per(nums,0,ans,vis);
        return ans;
    }
};

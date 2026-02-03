class Solution {
public:
    void can(int i,int n,vector<int>& nums,vector<vector<int>> &ans,vector<int> ds){
        if(i==n+1){
            return;
        }
        ans.push_back(ds);
        for(int ind = i;ind<n;ind++){
            ds.push_back(nums[ind]);
            can(ind+1,n,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        can(0,nums.size(),nums,ans,ds);
        return ans;
    }
};

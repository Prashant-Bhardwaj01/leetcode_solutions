class Solution {
public: 
    void dfs(int idx, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& sub){
        if(idx >= arr.size() || target < 0){
            return ;
        }
        
        if(target == 0){
        ans.push_back(sub);
        return ;
        }
        for(int i=idx;i<arr.size();i++){
            sub.push_back(arr[i]);
            dfs(i,arr,target-arr[i],ans,sub);
            sub.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        dfs(0,candidates,target, ans, sub);
        return ans;
    }
};

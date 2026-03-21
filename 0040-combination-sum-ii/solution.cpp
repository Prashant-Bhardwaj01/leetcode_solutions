class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, vector<int>& sub, vector<int>& arr, int target){
        if(target == 0){
            ans.push_back(sub);
            return ;
        }
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]== arr[i-1]) continue;
            if(arr[i] > target) break;
            sub.push_back(arr[i]);
            dfs(i+1, sub, arr, target - arr[i]);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> sub;
        dfs(0, sub, arr, target);
        return ans;
    }
};

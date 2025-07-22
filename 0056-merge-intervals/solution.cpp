class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        ans.push_back(arr[0]);
        for(int i=0;i<arr.size();i++){
            vector<int>& last = ans.back();
            vector<int>& curr = arr[i];
            if(curr[0] <= last[1])
            last[1] = max(last[1],curr[1]);
            else
            ans.push_back(curr);
        }
        return ans;
    }
};

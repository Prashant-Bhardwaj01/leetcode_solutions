class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i,int& n, int& k, vector<int>& sub){
        if(sub.size() == k){
            ans.push_back(sub);
            return ;
        }
        if(i>n) return;
        sub.push_back(i);
        dfs(i+1,n,k,sub);
        sub.pop_back();
        dfs(i+1,n,k,sub);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> sub;
        dfs(1,n,k,sub);
        return ans;
    }
};

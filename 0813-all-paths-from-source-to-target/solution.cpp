class Solution {
public:
    void dfs(int i, int n , vector<vector<int>>& graph, vector<vector<int>>& ans,vector<int>& sub){
        
        if(i==n-1){
            ans.push_back(sub);
            return;
        }
        for(int nbr : graph[i]){
            sub.push_back(nbr);
            dfs(nbr, n, graph, ans, sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> sub = {0};
        dfs(0,n,graph,ans,sub);
        return ans;
    }
};

class Solution {
public:
    void dfs(int node, unordered_set<int>& nodes,int &edge_count, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        nodes.insert(node);
        for(int i : adj[node]){
            edge_count++;
            if(!visited[i]){
                dfs(i,nodes,edge_count,adj,visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                unordered_set<int> nodes;
                int edgecount = 0;
                dfs(i,nodes,edgecount,adj,visited);
                int size = nodes.size();
                if(edgecount / 2 == (size * (size - 1))/ 2){
                    count++;
                }
            }
        }
        return count;
    }
};

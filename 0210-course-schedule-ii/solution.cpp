class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(auto i : edge){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        int c=0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            c++;
            for(int i: adj[front]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        if(c!=n) return {};
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
